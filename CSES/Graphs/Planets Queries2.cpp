#include <bits/stdc++.h>

using namespace std;

vector<int> which_cycle;

vector<vector<int>> lift;

vector<bool> visited;
vector<bool> current_dfs;

int num_nodes, num_queries;

int main () {
    ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_nodes >> num_queries;
    lift.resize(30, vector<int> (num_nodes));
    for (int i = 0; i < num_nodes; i++) {
        cin >> lift[0][i]; --lift[0][i];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 0; j < num_nodes; j++) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    for (auto a : lift){
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
}