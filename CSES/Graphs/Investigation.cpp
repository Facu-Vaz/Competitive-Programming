#include <bits/stdc++.h>

using namespace std;

int num_nodes, num_conexions, a, b, c;
long long INF = LONG_LONG_MIN; int MOD = 1e9 + 7;
vector<vector<int>> adj;
vector<vector<int>> cost;
vector<long long> dis;
vector<bool> processed;
vector<int> paths_num;
vector<int> min_nodes;
vector<int> max_nodes;

int main() {
    //ifstream cin("input.in");
    cin >> num_nodes >> num_conexions; 
    adj.resize(num_nodes+1);
    cost.resize(num_nodes+1);

    dis.resize(num_nodes+1, INF);
    processed.resize(num_nodes+1, false);
    min_nodes.resize(num_nodes+1, INT_MAX);
    paths_num.resize(num_nodes+1, 0);
    max_nodes.resize(num_nodes+1, -1);

    for (int n = 0; n < num_conexions; n++) {
        cin >> a >> b >> c;
        adj[a].push_back(b); cost[a].push_back(-c);
    }

    priority_queue<pair<long long, long long>> q; q.push({0, 1});
    bool done = false; 
    dis[1] = 0; paths_num[1] = 1; min_nodes[1] = 0; max_nodes[1] = 0;
    long long actual_node, actual_cost, neigh_node, neigh_cost;

    while (!q.empty() && !done){
        tie(actual_cost, actual_node) = q.top(); q.pop();
        //cout << actual_node << " - " << actual_cost << " - ";
        if (processed[actual_node]) continue;
        if (actual_node == num_nodes) done = true;
        processed[actual_node] = true;
        for (int n = 0; n < adj[actual_node].size(); n++) 
        {
            neigh_node = adj[actual_node][n]; neigh_cost = cost[actual_node][n];
            //cout << neigh_node << " ";
            if (actual_cost + neigh_cost > dis[neigh_node]) 
            {
                dis[neigh_node] = actual_cost + neigh_cost;
                paths_num[neigh_node] = paths_num[actual_node];
                min_nodes[neigh_node] = min_nodes[actual_node] + 1;
                max_nodes[neigh_node] = max_nodes[actual_node] + 1;
                q.push({dis[neigh_node], neigh_node});
            }
            else if (actual_cost + neigh_cost == dis[neigh_node]) 
            {
                paths_num[neigh_node] = (paths_num[actual_node] + paths_num[neigh_node]) % MOD;
                min_nodes[neigh_node] = min(min_nodes[actual_node] + 1, min_nodes[neigh_node]);
                max_nodes[neigh_node] = max(max_nodes[actual_node] + 1, max_nodes[neigh_node]);
            }
        }
        //cout << endl;
        //for (auto u : dis) cout << -u << " ";
        //cout << endl;
    }
    cout << -dis[num_nodes] << " " << paths_num[num_nodes] << " " << min_nodes[num_nodes] << " " << max_nodes[num_nodes];
}