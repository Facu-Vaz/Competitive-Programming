#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> cost;
vector<int> distances;
vector<int> paths_num;
vector<bool> processed;
int nodes_num, conexions_num;
int a, b, c, start, stop;
int INF = INT_MIN;

int main() {
    ifstream cin("ambulancia.in");

    cin >> nodes_num >> conexions_num >> start >> stop;
    adj.resize(nodes_num+1);
    cost.resize(nodes_num+1);
    distances.resize(nodes_num+1, INF);
    paths_num.resize(nodes_num+1, 0);
    processed.resize(nodes_num+1, false);
    for (int i = 0; i < conexions_num; i++) {
        cin >> a >> b >> c;
        adj[a].push_back(b); cost[a].push_back(-c);
        adj[b].push_back(a); cost[b].push_back(-c);
    }

    priority_queue<pair<int, int>> q; 
    q.push({0, start}); bool done = false; int actual, distance, neighbour, gasto;
    distances[start] = 0; paths_num[start] = 1;
    while (!done && !q.empty())
    {
        tie(distance, actual) = q.top(); q.pop();
        cout << actual << " - " << distance << " --> ";
        if (processed[a]) continue;
        processed[actual] = true;
        for (int n = 0; n < adj[actual].size(); n++) {
            neighbour = adj[actual][n];
            gasto = cost[actual][n];
            cout << neighbour << " " << distance + gasto << " - ";
            if (distance + gasto > distances[neighbour]) {
                distances[neighbour] = distance + gasto; 
                paths_num[neighbour] = paths_num[actual];
                q.push({distances[neighbour], neighbour});
            }
            else if (distance + gasto == distances[neighbour]) {
                paths_num[neighbour] += paths_num[actual];
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= nodes_num; i++)
    {
        cout << i << " " << distances[i] << " " << paths_num[i] << endl;
    }
}