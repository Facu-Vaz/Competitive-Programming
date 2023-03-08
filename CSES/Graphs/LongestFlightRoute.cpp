#include <bits/stdc++.h>

using namespace std;

int nodes_num, edges_num, a, b;
vector<vector<int>> adj;
vector<int> top_sorted;
vector<bool> processed;
vector<int> max_distance;
vector<int> father;

void dfs_topsorted(int x) {
    processed[x] = true;
    for (auto n : adj[x]) {
        if (!processed[n]) dfs_topsorted(n);
    }
    top_sorted.push_back(x);
}

int main() {
    
    cin >> nodes_num >> edges_num;
    adj.resize(nodes_num+1);
    processed.resize(nodes_num+1, false);
    max_distance.resize(nodes_num+1, INT_MIN);  
    father.resize(nodes_num+1, -1);
    for (int i = 0; i < edges_num; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= nodes_num; i++) {
        if (!processed[i]) dfs_topsorted(i);
    }
    reverse(top_sorted.begin(), top_sorted.end());

    max_distance[1] = 0; int start;
    for (int i = 0; i < nodes_num; i++) {
        if (top_sorted[i] == 1) {
            start = i; break;
        }
    }
    int actual;
    for (int i = start; i < nodes_num; i++) {
        actual = top_sorted[i];
        for (auto n : adj[actual]) {
            if (max_distance[n] < max_distance[actual] + 1) {
                max_distance[n] = max_distance[actual] + 1;
                father[n] = actual;
            }
        }
    }

    if (max_distance[nodes_num]+1 < 0) cout << "IMPOSSIBLE";
    else {
        cout << max_distance[nodes_num]+1 << endl;
        int p = nodes_num;
        vector<int> ret {nodes_num}; 
        while (father[p] != -1) {
            p = father[p];
            ret.push_back(p);
        }
        for (int i = ret.size()-1; i >= 0; i--) cout << ret[i] << " ";
    }    
}