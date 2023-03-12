#include <bits/stdc++.h>

using namespace std;

int INF = INT_MAX;
vector<vector<pair<int, int>>> adj;
vector<int> dij_1;
vector<int> dij_2;
vector<bool> p_dij_1;
vector<bool> p_dij_2;

vector<bool> pros;
vector<vector<int>> adj2;

vector<bool> visited;
vector<int> topsorted;
int num_nodes, num_conexions, start, finish, a , b, c;

void topsort(int x) {
    visited[x] = true;
    for (auto n : adj2[x]) {
        if (!visited[n]) topsort(n);
    }
    topsorted.push_back(x);
}

int main() {
    ifstream cin("ambulancia.in");
    ofstream cout("ambulancia.out");
    cin >> num_nodes >> num_conexions >> start >> finish;
    adj.resize(num_nodes+1);
    dij_1.resize(num_nodes+1, INF);
    dij_2.resize(num_nodes+1, INF);
    p_dij_1.resize(num_nodes+1, false);
    p_dij_2.resize(num_nodes+1, false);

    pros.resize(num_nodes+1, false);
    adj2.resize(num_nodes+1);

    visited.resize(num_nodes+1, false);

    for (int i = 0; i < num_conexions; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }   
    int actual_node, actual_neigh, actual_cost, actual_travel;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; 
    q.push({0, start});
    dij_1[start] = 0;
    while (!q.empty()) {
        tie(actual_cost, actual_node) = q.top(); q.pop();
        //cout << actual_node << " " << actual_cost << " --> ";
        if (p_dij_1[actual_node]) continue;
        p_dij_1[actual_node] = true;
        for (auto n : adj[actual_node]) {
            tie(actual_neigh, actual_travel) = n;
            //cout << actual_neigh << " " << actual_cost + actual_travel << " - ";
            if (actual_cost + actual_travel < dij_1[actual_neigh]) {
                dij_1[actual_neigh] = actual_cost + actual_travel;
                q.push({dij_1[actual_neigh], actual_neigh});
            }
        }
        //cout << endl;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
    q2.push({0, finish}); dij_2[finish] = 0;
    //cout << endl;
    while (!q2.empty()) {
        tie(actual_cost, actual_node) = q2.top(); q2.pop();
        //cout << actual_node << " " << actual_cost << endl;
        if (p_dij_2[actual_node]) continue;
        p_dij_2[actual_node] = true;
        for (auto n : adj[actual_node]) {
            tie(actual_neigh, actual_travel) = n;
            if (actual_cost + actual_travel < dij_2[actual_neigh]) {
                dij_2[actual_neigh] = actual_cost + actual_travel;
                q2.push({dij_2[actual_neigh], actual_neigh});
            }
        }
    }

    for (actual_node = 1; actual_node <= num_nodes; actual_node++)
    {
        for (auto n : adj[actual_node]) {
            actual_neigh = n.first;
            if (actual_neigh < actual_node) continue;
            if (dij_1[actual_node] > dij_1[actual_neigh] && dij_2[actual_node] < dij_2[actual_neigh]) {
                adj2[actual_neigh].push_back(actual_node);
            }
            if (dij_1[actual_node] < dij_1[actual_neigh] && dij_2[actual_node] > dij_2[actual_neigh]) {
                adj2[actual_node].push_back(actual_neigh);
            }
        }
    }

    for (int i = 1; i <= num_nodes; i++) {
        if (!visited[i]) topsort(i);
    }
    vector<int> ret (num_nodes+1, 0); ret[start] = 1;
    for (int i = num_nodes-1; i >= 0; i--) {
        for (auto n : adj2[topsorted[i]]) {
            ret[n] += ret[topsorted[i]];
        }
    }

    cout << ret[finish] << endl;
}