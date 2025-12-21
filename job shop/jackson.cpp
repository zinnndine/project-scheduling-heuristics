#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n;
vector<vector<int>> p;
vector<int> F;
vector<pair<int, int >> order;
vector<int> ordononmentm_1;
vector<int> ordononmentm_2;



int  fill() {
    cout << "Enter the number of tasks : ";
    cin >> n;
    p.resize(n, vector<int>(2));
    F.resize(n);
    int h;
    int z;
    pair<int, int > r;
    pair<int, int > standard ={ 1, 2 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "task " << i + 1 << " in machine " << j + 1 << "  time" << "  (if this task dont run in this machine put 0) :";
            cin >> p[i][j];
        }
        if (p[i][0] != 0 && p[i][1] != 0) {
           
            cout << "the first machine task " << i + 1 <<  "pass by : ";
            cin >> h;
            r.first = h;
            cout << "the second machine task " << i + 1 << "pass by : ";
            cin >> z;
            r.second = z;
            order.push_back(r);
            
        }
        else
        {
            order.push_back(standard);
        }
    }


    return 0;
}





void prtin(vector<int>& k,int j) {
    int y=0;
    for (int i : k)
    {
        y = 1 + y ;
        cout << "task at position " << y  << " is " << i + 1 << " in machine machine " << j << "\n";
    }
}


vector<int> jonhson(vector<int> OP) {
    vector<int> X;
    vector<int> Y;
    vector<int> O;

    for (int i: OP) {
        if (p[i][0] <= p[i][1]) {
            X.push_back(i);
        }
        else {
            Y.push_back(i);
        }
    }

    for (int i = 0; i < X.size(); i++) {
        for (int j = i + 1; j < X.size(); j++) {
            if (p[X[j]][0] < p[X[i]][0]) {
                swap(X[i], X[j]);
            }
        }
    }

    for (int i = 0; i < Y.size(); i++) {
        for (int j = i + 1; j < Y.size(); j++) {
            if (p[Y[j]][1] > p[Y[i]][1]) {
                swap(Y[i], Y[j]);
            }
        }
    }

    for (int task : X) {
        O.push_back(task);
    }

    for (int task : Y) {
        O.push_back(task);
    }
    return O;
}




void  jokson() {
    vector<int> O_one;
    vector<int> O_two;
    vector<int> O_one_two;
    vector<int> O_two_one;
    vector<vector<int>> ss;
    for (int i = 0; i < n; i++)
    {

            if (p[i][0]==0) {
                 O_two.push_back(i);
            }
            if (p[i][1] == 0) {
                O_one.push_back(i);
            }
            else {
                if (order[i].first > order[i].second && p[i][0]*p[i][1]!= 0) {
                    O_two_one.push_back(i);
                }
                if (order[i].second > order[i].first && p[i][0] * p[i][1] != 0)
                {
                    O_one_two.push_back(i);
                } 

        }
    }

    O_one_two = jonhson(O_one_two);
    O_two_one = jonhson(O_two_one);


    for (int i : O_one_two)
    {
        ordononmentm_1.push_back(i);
    }
    for (int i : O_one)
    {
        ordononmentm_1.push_back(i);
    }
    for (int i : O_two_one)
    {
        ordononmentm_1.push_back(i);
        ordononmentm_2.push_back(i);
    }
    for (int i : O_two)
    {
        ordononmentm_2.push_back(i);
    }
    for (int i : O_one_two)
    {
        ordononmentm_2.push_back(i);
    }
    


}

int main()
{
    fill();
    jokson();
    prtin(ordononmentm_1,1);
    prtin(ordononmentm_2,2);
}

