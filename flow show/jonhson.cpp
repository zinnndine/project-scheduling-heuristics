

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
    vector<vector<int>> p;
vector<int> F;



int  fill() {
    cout << "Enter the number of tasks : ";
    cin >> n;
    p.resize(n, vector<int>(2));
    F.resize(n);
    
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < 2; j++)
    {
        cout << "task " <<i+1 <<" in machine " << j+1 << "  time :" ;
        cin >> p[i][j];   
    }
    }


    return 0;
}


vector<int> ordo(int n, vector<vector<int>>& p) {
    vector<int> X;
    vector<int> Y;
    vector<int> O;

    for (int i = 0; i < n; i++) {
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

 
void prtin(vector<int>& k) {
 
    for (int i = 0; i <k.size(); i++)
    {
        cout << "task at position " << i+1 << " is : " << k[i] + 1 << "\n";
    }
}



int main()
{
    fill();
  F =  ordo(n, p);
  prtin(F);
}
