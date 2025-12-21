#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

int n;

vector<vector<int>> p;

void  fill() {
    cout << "Enter the tasks number : ";
    cin >> n;
    p.resize(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "task " << i + 1 << " in machine " << j + 1 << "  time :";
            cin >> p[i][j];
        }
    }
}


void LAPT(vector<vector<int>>&p)
{
    vector<int> t;
    int k;
    int h;
    vector<int> O1;
    vector<int> O2;
    vector<int> F;
    vector<vector<int>> p_copy(n, vector<int>(2, 0));
    t.push_back(0);
    t.push_back(0);
    for (int i = 0; i < n; i++) {
        F.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        p_copy[i][0] = p[i][0];
        p_copy[i][1] = p[i][1];
    }

    while (F.size() != 0) {

        if (t[0] <= t[1]) {
            k = p_copy[0][1];
            h = 0;
            for (int i = 0; i < n; i++) {
                if (p_copy[i][1] > k && p_copy[i][0] >= 0 && p_copy[i][1] >= 0) {
                    k = p_copy[i][1];
                    h = i;
                }
            }
            if (p_copy[h][0] == -1) continue;



            t[0] = t[0] + p_copy[h][0]; 


            O1.push_back(h);
            p_copy[h][1] = -1;
            p_copy[h][0] = -1;

            for (int i = 0; i < F.size(); i++) {
                if (F[i] == h) {
                    F.erase(F.begin() + i);
                    break;
                }
            }
        }
        else if (t[1] <= t[0]) {
            k = p_copy[0][0];
            h = 0;
            for (int i = 0; i < n; i++) {
                if (p_copy[i][0] > k && p_copy[i][0] >= 0 && p_copy[i][1] >= 0) {
                    k = p_copy[i][0];
                    h = i;
                }
            }
            if (p_copy[h][0] == -1) continue;


            t[1] = t[1] + p_copy[h][1]; 


            O2.push_back(h);
            p_copy[h][0] = -1;
            p_copy[h][1] = -1;

            for (int i = 0; i < F.size(); i++) {
                if (F[i] == h) {
                    F.erase(F.begin() + i);
                    break;
                }
            }
        }


    }



    for (int i : O1)
    {
        O2.push_back(i);
        t[1] = t[1] + p[i][1];
    }

    for (int i : O2)
    {
        if (find(O1.begin(), O1.end(), i) == O1.end()) {
            O1.push_back(i);
            t[0] = t[0] + p[i][0];
        }
    }

    cout << "\n final order:\nO1: ";
    for (int i : O1) cout << i << " ";
    cout << "\n O2: ";
    for (int i : O2) cout << i << " ";
    cout << endl;


    cout << "machine  1 max TIME  " << t[0] << "\n";
    cout << "machine  2 max TIME  " << t[1] << "\n";

    
}



void GARD(vector<vector<int>>&p)
{
    vector<int> t;
    int mini;
    int h;
    int k;
    int temp;
    vector<int> O1;
    vector<int> O2;
    vector<int> F;
    vector<int> M;
    pair<int, int> f= { 1,1 };
    bool added = false;

    t.push_back(0);
    t.push_back(0);
    for (int i = 0; i < n; i++) {
        F.push_back(i);
        M.push_back(i);
    }

    mini = p[0][0];
    h = 0;
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (mini<p[i][j]) {
            mini = p[i][j];
            h = i;
            k = j;
            }
        }
     
    }
    mini = h;

    if (k == 1) {
        O1.push_back(h);
        t[0] += p[h][0];
        auto it = find(F.begin(), F.end(), h);  
        if (it != F.end()) F.erase(it);          
    }
    else if (k == 0) {
        O2.push_back(h);
        t[1] += p[h][1];
        auto it = find(M.begin(), M.end(), h);  
        if (it != M.end()) M.erase(it);          
    }
    while (F.size() !=0 && M.size()!=0)
    {
        if (t[k]>=p[mini][1-k] && added ==false) {
            
            if(k==0 ){
                auto it = find(F.begin(), F.end(), mini);
                if (it != F.end()) {
                    t[k] = t[k] + p[mini][k];
                    F.erase(it);
                    O1.push_back(mini);
                    added = true;
                }

                
            }
            else if (k==1) {
                auto it = find(M.begin(), M.end(), mini);
                if (it != M.end()) {
                    t[k] = t[k] + p[mini][k];
                    M.erase(it);
                    O2.push_back(mini);
                   added = true;
                }
            }
        }
         if (t[0]*f.first <= t[1]) {
            if (F.size() == 0) {
                f.first = 10000;
                continue;
            }
                for (int i: F) {
                        h = i;
                        break;
                }
                t[0] = t[0] + p[h][0];
                O1.push_back(h);
                for (int i = 0; i < F.size(); i++) {
                    if (F[i] == h) {
                        F.erase(F.begin() + i);
                        break;
                    }
                }
            }
     else if (t[1]* f.second <= t[0]) {
            if (M.size() == 0) { 
                f.second = 10000;
                continue; 
            }

                for (int i:M) {
                    h = i;
                    break;
                }
                t[1] = t[1] + p[h][1];
                O2.push_back(h);
                for (int i = 0; i < M.size(); i++) {
                    if (M[i] == h) {
                        M.erase(M.begin() + i);
                        break;
                    }
                }
            }
    }



    for (int i : O1)
    {
        if (find(O2.begin(), O2.end(), i) == O2.end()) {
            O2.push_back(i);
            t[1] = t[1] + p[i][1];
        }
    }

    for (int i : O2)
    {
        if (find(O1.begin(), O1.end(), i) == O1.end()) {
            O1.push_back(i);
            t[0] = t[0] + p[i][0];
        }
    }



    cout << "\n final order:\nO1: ";
    for (int i : O1) cout << i << " ";
    cout << "\n O2: ";
    for (int i : O2) cout << i << " ";
    cout << endl;


    cout << "machine  1 max TIME  " << t[0] << "\n";
    cout << "machine  2 max TIME  " << t[1] << "\n";

}


void Gonzlaz(vector<vector<int>>&p) { 
    vector<int> t;
    vector<int> O1;
    vector<int> O2;
    vector<int> A;
    vector<int> B;
    int J1=0;
    int J2=0;
    int a;
    int b;
    int maxi = -1;
    int max_value = -1;
    t.push_back(0);
    t.push_back(0);


    for (int i = 0; i < n; i++) {
            if (p[i][0] < p[i][1]) {
                B.push_back(i);
            }
            else
            {
                A.push_back(i);
            }
            J1 += p[i][0];
            J2 += p[i][1];

        }

    for (int i = 0; i < A.size(); i++)
        {
            if( max_value <= p[A[i]][1]){
                max_value = p[A[i]][1];
            }
        }
    for (int i = 0; i < n; i++)
    {
     if (max_value <= p[i][0]) {
        maxi = i;
      }
    }
    a = maxi;

    max_value = -1;
    for (int i = 0; i < B.size(); i++)
    {
        if (max_value <= p[B[i]][0]) {
            max_value = p[B[i]][0];
        }
    }
    maxi = -1;
    for (int i = 0; i < n; i++)
    {
            if (max_value < p[i][1] && i != a ) {
                maxi = i;
            }
    }
    b = maxi;

    auto it = find(B.begin(), B.end(), b);
    if (it != B.end()) B.erase(it);

    it = find(B.begin(), B.end(), a);
    if (it != B.end()) B.erase(it);

    it = find(A.begin(), A.end(), b);
    if (it != A.end()) A.erase(it);

    it = find(A.begin(), A.end(), a);
    if (it != A.end()) A.erase(it);
    int temp1 = 0, temp2 = 0;
    if (b == -1)temp1 = 0;
    else { temp1 = p[b][0];}
    if (a == -1)temp2 = 0;
    else { temp2 = p[a][1]; }
    if (J1- temp1>=J2-temp2)
    {
       if(b!=-1) O1.push_back(b);
       if (b != -1)t[0] += p[b][0];
        for (int i = 0; i <B.size(); i++)
        {
            O1.push_back(B[i]);
            t[0] += p[B[i]][0];
        }        
        for (int i = 0; i < A.size(); i++)
        {
            O1.push_back(A[i]);
            t[0] += p[A[i]][0];

        }
        if (a != -1) O1.push_back(a);
        if (a!= -1) t[0] += p[a][0];


        if (a != -1) O2.push_back(a);
        if (b != -1)O2.push_back(b);
        if (a != -1)t[1] += p[a][1];
        if (b != -1)t[1] += p[b][1];

        for (int i = 0; i < B.size(); i++)
        {
            O2.push_back(B[i]);
            t[1] += p[B[i]][1];
        }
        for (int i = 0; i < A.size(); i++)
        {
            O2.push_back(A[i]);
            t[1] += p[A[i]][1];
        }
    }
    else
    {
        if (a != -1) O2.push_back(a);
        if (a != -1) t[1] += p[a][1];
        for (int i = 0; i < A.size(); i++)
        {
            O2.push_back(A[i]);
            t[1] += p[A[i]][1];

        }
        for (int i = 0; i < B.size(); i++)
        {
            O2.push_back(B[i]);
            t[1] += p[B[i]][1];

        }
        if (b != -1)O2.push_back(b);
        if (b != -1)t[1] += p[b][1];


        if (b != -1)O1.push_back(b);
        if (b != -1)t[0] += p[b][0];
        if (a != -1)O1.push_back(a);
        if (a != -1)t[0] += p[a][0];

        for (int i = 0; i < A.size(); i++)
        {
            O1.push_back(A[i]);
            t[0] += p[A[i]][0];

        }
        for (int i = 0; i < B.size(); i++)
        {
            O1.push_back(B[i]);
            t[0] += p[B[i]][0];

        }
    }
    cout << "\n final order:\nO1: ";
    for (int i : O1) cout << i << " ";
    cout << "\n O2 : ";
    for (int i : O2) cout << i << " ";
    cout << endl;


    cout << "machine  1 max TIME  " << t[0] << "\n";
    cout << "machine  2 max TIME  " << t[1] << "\n";
    
}




int main() {
    fill();
    int alt;
    cout << "what algorithme to choose :\n";
    cout << "1-lapt\n";
    cout << "2-gard\n";
    cout << "3-Gonzlaz\n";
    cout << "--->";
    cin >> alt;
    if (alt == 1) LAPT(p);
    if (alt == 2) GARD(p);
    if (alt == 3) Gonzlaz(p);

    return 0;
}
