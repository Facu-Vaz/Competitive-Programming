#include <bits/stdc++.h>

using namespace std;

vector<int> ret;
vector<vector<int>> adj;

int num_nodes;

int dfs (int x) {

}

int main () {
    cin >> num_nodes;
    adj.resize(num_nodes)
    ret.resize(num_nodes, 0);

    int a;
    for (int i = 1; i < num_nodes; i++) {
        cin >> a;
        adj[i].push_back(a);
    }

        

    for (auto r : ret) cout << r << "\n";
}