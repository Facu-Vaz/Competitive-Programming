#include <bits/stdc++.h>

using namespace std;

vector<int> which_cycle;
vector<int> pos_cycle;
vector<int> len_cycle;



vector<vector<int>> lift;

vector<bool> visited;
vector<bool> current_dfs;
vector<bool> is_cycle;

int num_nodes, num_queries;
int num_cycles = 0; int actual_id;
int current_cycle;
bool in_cycle; int repeated;

void dfs (int n) {
    if (current_dfs[n]) {
        in_cycle = true; repeated = n;
        current_cycle = num_cycles; num_cycles++;
        return;
    }
    current_dfs[n] = true;
    if (!visited[lift[0][n]]) dfs(lift[0][n]);
    current_dfs[n] = false;
    if (in_cycle) {
        which_cycle[n] = current_cycle;
        pos_cycle[n] = actual_id; actual_id++;
        is_cycle[n] = true;
    }
    if (n == repeated) {
        in_cycle = false;
        len_cycle.push_back(actual_id);
        actual_id = 1;
    }
    if (!in_cycle) {
        pos_cycle[n] = actual_id;
        actual_id++;
    }
}

int main () {
    ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_nodes >> num_queries;
    lift.resize(30, vector<int> (num_nodes));
    which_cycle.resize(num_nodes, -1);
    pos_cycle.resize(num_nodes, -1);

    visited.resize(num_nodes, false);
    current_dfs.resize(num_nodes, false);
    is_cycle.resize(num_nodes, false);

    for (int i = 0; i < num_nodes; i++) {
        cin >> lift[0][i]; --lift[0][i];
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 0; j < num_nodes; j++) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    for (int n = 0; n < num_nodes; n++) {
        if (!visited[n]) {
            actual_id = 0;
            in_cycle = false; dfs(n);
        }
    }

    for (auto a : lift){
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "In cycle: ";
    for (auto a : is_cycle) cout << a << " ";
    cout << endl << endl;
    cout << "Which cycle: ";
    for (auto a : which_cycle) cout << a << " ";
    cout << endl << endl;
    cout << "Pos cycle: ";
    for (auto a : pos_cycle) cout << a << " ";
}