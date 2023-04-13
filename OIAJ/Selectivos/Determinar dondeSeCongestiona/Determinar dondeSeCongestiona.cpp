#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<vector<int>> id;
vector<int> trafic; 

int num_nodes, num_conexions;
int a, b, cost;

int recorrer (int node, int from, vector<vector<int>>& new_adj) {
    if (new_adj[node].size() == 0) {
        trafic[id[from][node]] += 1;
        return 1;
    }
    else {
        int sum = 1;
        for (auto n : new_adj[node]) {
            sum += recorrer(n, node, new_adj);
        }
        
        if (from != -1) {
            trafic[id[from][node]] += sum;
        }
    }
}

void solve (int start) {
    //cout << start << endl;
    vector<vector<int>> new_adj (num_nodes);
    vector<int> visited (num_nodes, false);
    vector<int> min_distance (num_nodes, INT_MAX); min_distance[start] = 0;
    priority_queue<pair<int, pair<int, int>>> q; q.push({0, {-1, start}});
    int done = 0; pair<int, int> viaje;
    int node_actual, cost_actual, from_actual, neigh, travel;

    while (!q.empty() && done != num_nodes) {
        tie(cost_actual, viaje) = q.top(); q.pop();
        tie(from_actual, node_actual) = viaje;
        if (visited[node_actual]) continue;
        done += 1;
        visited[node_actual] = true;
        if (from_actual != -1) {
            new_adj[from_actual].push_back(node_actual);
        }
        for (int n = 0; n < adj[node_actual].size(); n++) {
            tie(neigh, travel) = adj[node_actual][n];
            if (min_distance[neigh] <= cost_actual + travel) continue;
            min_distance[neigh] = cost_actual + travel;
            q.push({-min_distance[neigh], {node_actual, neigh}});
        }
    }

    recorrer(start, -1, new_adj);

    // for (int n = 0; n < num_nodes; n++) {
    //     cout << n << ": ";
    //     for (auto a : new_adj[n]) {
    //         cout << a << ", ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : trafic) cout << a << " ";
    // cout << endl;
}

int main () {
    ifstream cin("congestion.in");
    ofstream cout("congestion.out");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_nodes >> num_conexions;
    adj.resize(num_conexions);
    id.resize(num_conexions, vector<int> (num_conexions));
    trafic.resize(num_conexions+1, 0);

    for (int c = 1; c <= num_conexions; c++) {
        cin >> a >> b >> cost; a--; b--;
        adj[a].push_back({b, cost});
        id[a][b] = c;
    }

    for (int n = 0; n < num_nodes; n++) solve(n);

    int best = INT_MIN;
    vector<int> ret;
    for (int i = 1; i <= num_conexions; i++) {
        if (trafic[i] > best) {
            best = trafic[i]; ret.clear();
            ret.push_back(i);
        }
        else if (trafic[i] == best) ret.push_back(i);
    }

    cout << ret.size() << " " << best << endl;
    for (auto r : ret) cout << r << " ";

}