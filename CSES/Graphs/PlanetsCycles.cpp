#include <bits/stdc++.h>

using namespace std;

vector<int> to;
vector<vector<int>> inverse;
vector<int> next_component;
vector<bool> visited;
vector<int> process;
vector<int> component;
vector<int> weigths;

vector<bool> component_visited;
vector<int> topsorted;

int num_nodes, num_components;

void dfs (int x) {
    visited[x] = true;
    if (!visited[to[x]]) dfs(to[x]);
    process.push_back(x);
}

int dfs_reversed (int x) {
    visited[x] = true;
    //cout << x;
    int sum = 0;
    for (auto n : inverse[x]) {
        if (!visited[n]) sum = dfs_reversed(n);
    }
    //cout << " ";
    component[x] = num_components;
    return sum + 1;
}

void topsort (int x) {
    component_visited[x] = true;
    if (next_component[x] != -1) {
        if (!visited[next_component[x]]) topsort(next_component[x]);
    }
    topsorted.push_back(x);
}

int main() {
    cin >> num_nodes;

    to.resize(num_nodes);
    inverse.resize(num_nodes);
    visited.resize(num_nodes, false);
    component.resize(num_nodes);

    for (int n = 0; n < num_nodes; n++) {
        cin >> to[n]; to[n]--;
        inverse[to[n]].push_back(n);
    }

    for (int n = 0; n < num_nodes; n++) {
        if (!visited[n]) dfs(n);
    }
    visited.clear(); visited.resize(num_nodes, false);
    num_components = 0; int sum;
    for (int n = num_nodes-1; n >= 0; n--) {
        if (!visited[process[n]]) {
            //cout << process[n] << " -- ";
            sum = dfs_reversed(process[n]);
            //cout << endl;
            num_components++;
            weigths.push_back(sum);
        }        
    }   

    next_component.resize(num_components);

    for (int n = 0; n < num_nodes; n++) {
        if (weigths[component[n]] > 1) {
            next_component[component[n]] = -1;
        } else {
            next_component[component[n]] = component[to[n]];
        }
    }

    component_visited.resize(num_components, false);
    for (int c = 0; c < num_components; c++) {
        if (!component_visited[c]) topsort(c);
    }

    // cout << "Weights components: ";
    // for (auto w : weigths) cout << w << " ";
    // cout << endl;

    reverse(topsorted.begin(), topsorted.end());
    for (auto c : topsorted) {
        if (next_component[c] == c) continue;
        if (next_component[c] != -1) weigths[c] += weigths[next_component[c]];
    }

    for (int n = 0; n < num_nodes; n++) cout << weigths[component[n]] << " ";

    // cout << endl;
    // cout << "Weights components: ";
    // for (auto w : weigths) cout << w << " ";




    // for (auto n : next_component) cout << n << " ";
    // cout << endl;
    // cout << "Component of node: ";
    // for (auto c : component) cout << c << " ";
    // // cout << endl;
    // cout << "Next component: ";
    // for (int c = 0; c < num_components; c++) {
    //     cout << c << " --> " << next_component[c] << endl;;
    // }
    // cout << endl;
    // cout << "Topsorted: ";
    // for (auto c : topsorted) cout << c << " ";
    // for (auto c : to) cout << c << " ";
    // cout << endl;

}