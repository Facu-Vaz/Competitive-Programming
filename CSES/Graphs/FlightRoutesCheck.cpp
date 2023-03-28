#include <bits/stdc++.h>    

using namespace std;

int num_nodes, num_conexions;
vector<vector<int>> adj_1;
vector<vector<int>> adj_2;
vector<bool> visited_1;
vector<bool> visited_2;

void dfs (int x, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[x] = true;
    //cout << x << " ";
    for (auto v : adj[x]) {
        if (!visited[v]) dfs(v, visited, adj);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_nodes >> num_conexions;
    adj_1.resize(num_nodes+1);
    adj_2.resize(num_nodes+1);

    visited_1.resize(num_nodes+1, false);
    visited_2.resize(num_nodes+1, false);

    int a, b;
    for (int c = 0; c < num_conexions; c++) {
        cin >> a >> b; 
        adj_1[a].push_back(b);
        adj_2[b].push_back(a);
    }
    dfs(1, visited_1, adj_1);
    for (int n = 2; n <= num_nodes; n++) {
        if (!visited_1[n]) {
            cout << "NO" << "\n";
            cout << 1 << " " << n;
            return 0;
        } 
    }

    dfs(1, visited_2, adj_2);
    for (int n = 2; n <= num_nodes; n++) {
        if (!visited_2[n]) {
            cout << "NO" << "\n";
            cout << n << " " << 1;
            return 0;
        } 
    }
    cout << "YES";

}