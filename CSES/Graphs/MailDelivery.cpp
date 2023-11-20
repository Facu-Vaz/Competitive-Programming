#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> adj;
vector<int> adj_unused;

vector<int> path;
stack<int> curr_path;

void find_hamilton_path() {
  
    // start from any vertex
    curr_path.push(0);
    int curr_v = 0; // Current vertex
 
    while (!curr_path.empty())
    {
        cout << curr_v << " ";
        cout << "A";
        // If there's remaining edge
        if (adj_unused[curr_v])
        {
            cout << "B";
            // Push the vertex
            curr_path.push(curr_v);
 
            // Find the next vertex using an edge
            int next_v = adj[curr_v].back();
 
            // and remove that edge
            adj_unused[curr_v]--;
            adj[curr_v].pop_back();
 
            // Move to next vertex
            curr_v = next_v;
            cout << "C";
        } 
        // back-track to find remaining circuit
        else
        {
            cout << "D";
            path.push_back(curr_v);
 
            // Back-tracking
            curr_v = curr_path.top();
            curr_path.pop();
            cout << "E";
        }
        cout << endl;
    }
    cout << "WOHO" << endl;
}

int main()
{
    ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    adj.resize(N);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int imp = 0;
    for (int i = 0; i < N; i++) {
        cout << i << " - " << adj[i].size() << endl;
        if (adj[i].size() % 2 == 1) imp++;
    }

    if (imp != 2 && imp != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    adj_unused.resize(N);
    for (int i = 0; i < N; i++) adj_unused[i] = adj.size();

    find_hamilton_path();
    cout << "HEEY" << endl;

    for (auto v : path) cout << v << " ";



    
}