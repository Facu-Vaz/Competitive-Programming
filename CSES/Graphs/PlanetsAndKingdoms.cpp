#include <bits/stdc++.h>

using namespace std;

int num_nodes, num_conexions;

vector<vector<int>> adj_1;
vector<vector<int>> adj_2;

int num_groups;

vector<int> process;
vector<bool> visited;
vector<int> group;

int grupo_actual;


void dfs (int x) {
    visited[x] = true;
    for (auto a : adj_1) {
        if (!visited[x]) dfs(x);
    }
    process.push_back(x);
}

void dfs_2 (int x) {
    group[x] = grupo_actual;
    for (auto a : adj_2[x]) {
        if (group[a] == 0) dfs_2(a);
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_nodes >> num_conexions;
    adj_1.resize(num_nodes+1);
    adj_2.resize(num_nodes+1);

    visited.resize(num_nodes+1, false);
    group.resize(num_nodes+1, 0);

    int a, b;
    for (int c = 0; c < num_conexions; c++) {
        cin >> a >> b;
        adj_1[a].push_back(b);
        adj_2[b].push_back(a);
    }

    num_groups = 0;

    for (int i = 1; i <= num_nodes; i++) {
        if (!visited[i]) dfs(i);
    }


    for (int i = num_nodes-1; i >= 0; i--) {
        cout << process[i] << " ";
        if (group[process[i]] == 0) {
            num_groups++;
            grupo_actual = num_groups;
            dfs_2(process[i]);
        }
    }

    //for (auto a : process) cout << a << " ";
    //cout << endl;
    cout << num_groups << endl;
    for (int i = 1; i <= num_nodes; i++) cout << group[i] << " ";
    
    for (int i )
}