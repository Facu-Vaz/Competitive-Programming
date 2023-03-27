#include <bits/stdc++.h>

using namespace std;

int num_nodes, num_queries;
int num_potencias = 30;
vector<vector<int>> tablita;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //ifstream cin("input.in");
    cin >> num_nodes >> num_queries;
    // for (auto a : potencias_de_dos) cout << a << " ";
    // cout << endl;


    tablita.resize(num_potencias, vector<int> (num_nodes+1, 0));
    for (int i = 1; i <= num_nodes; i++) cin >> tablita[0][i];
    for (int i = 1; i < num_potencias; i++) {
        for (int j = 1; j <= num_nodes; j++) {
            tablita[i][j] = tablita[i-1][tablita[i-1][j]];
        }
    }

    int start, k, temp;
    vector<int> ret;
    vector<vector<int>> potencias (num_queries);
    for (int i = 0; i < num_queries; i++) {
        cin >> start >> k;
        temp = k;
        for (int p = 0; temp > 0; p++) {
            if (temp % 2 == 1) {
                potencias[i].push_back(p);
            }
            temp /= 2;
        }
        temp = start;
        for (int p = potencias[i].size()-1; p >= 0; p--) {
            //cout << temp << " ";
            temp = tablita[potencias[i][p]][temp];
        }
        //cout << endl;   
        ret.push_back(temp);
    }
    //cout << endl;

    for (auto r : ret) cout << r << endl;

    // cout << endl;

    // for (auto a : tablita) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
    // for (auto a : potencias) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
}