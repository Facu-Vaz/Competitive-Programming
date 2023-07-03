#include <bits/stdc++.h>

using namespace std;

vector<int> ret;
vector<vector<int>> adj;
vector<bool> visited;

int num_nodes;

int dfs (int x) {
    visited[x] = true;
    int sum = 0;
    for (auto n : adj[x]) {
        if (!visited[n]) sum += dfs(n);
    }
    ret[x] = sum;
    return sum+1;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_nodes;

    adj.resize(num_nodes);
    ret.resize(num_nodes, 0);
    visited.resize(num_nodes, false);

    int a;
    for (int i = 1; i < num_nodes; i++) {
        cin >> a; 
        if (a == 0) continue;
        a--;
        adj[a].push_back(i);
    } dfs(0);
    for (auto r : ret) cout << r << " ";
}