#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> top_sorted;
vector<bool> visited;
vector<int> paths_num;
int nodes_num, conexions_num, a, b;
int MOD = 1e9 + 7;

void dfs_topsort(int x) {
    visited[x] = true;
    for (auto n : adj[x]) {
        if (!visited[n]) dfs_topsort(n);
    }
    top_sorted.push_back(x);
}

int main () {    
    cin >> nodes_num >> conexions_num;
    adj.resize(nodes_num+1);
    visited.resize(nodes_num+1, false);
    paths_num.resize(nodes_num+1, 0);

    for (int i = 0; i < conexions_num; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= nodes_num; i++) {
        if (!visited[i]) dfs_topsort(i);
    }
    int start = nodes_num-1; paths_num[1] = 1;
    while (top_sorted[start] != 1) start--;

    for (int i = start; i >= 0; i--) {

        for (auto n : adj[top_sorted[i]]) {
            paths_num[n] = (paths_num[n] + paths_num[top_sorted[i]]) % MOD;
        }
    }
    // for (auto i : paths_num) cout << i << " ";
    // cout << endl;
    cout << paths_num[nodes_num];
}