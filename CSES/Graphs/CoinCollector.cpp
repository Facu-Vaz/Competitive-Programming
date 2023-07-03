#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> adj;
vector<vector<long long>> adj_reversed;
vector<vector<long long>> adj_components;
vector<vector<bool>> check;
vector<long long> num_coins;
vector<long long> num_coins_component;
vector<bool> visited;
vector<bool> component_visited;
vector<long long> process;
vector<long long> componente;
vector<long long> topsorted;
long long num_nodos, num_conexiones, num_componentes;

void dfs (long long x) {
    visited[x] = true;
    for (auto n : adj[x]) {
        if (!visited[n]) dfs(n);
    }
    process.push_back(x);
}

void dfs_reversed (long long x) {
    visited[x] = true;
    for (auto n : adj_reversed[x]) {
        if (!visited[n]) dfs_reversed(n);
    }
    componente[x] = num_componentes;
}

void topsort (long long x) {
    component_visited[x] = true;
    for (long long n : adj_components[x]) {
        if (!component_visited[n]) topsort(n);
    }
    topsorted.push_back(x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_nodos >> num_conexiones;
    long long a, b;
    adj.resize(num_nodos);
    adj_reversed.resize(num_nodos);
    visited.resize(num_nodos, false);
    num_coins.resize(num_nodos);
    componente.resize(num_nodos, 0);


    for (long long n = 0; n < num_nodos; n++) cin >> num_coins[n];
    
    for (long long c = 0; c < num_conexiones; c++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj_reversed[b].push_back(a);
    }

    for (long long n = 0; n < num_nodos; n++) {
        if (!visited[n]) dfs(n);
    }
    visited.clear();
    visited.resize(num_nodos, false);
    num_componentes = 0;
    for (long long n = num_nodos-1; n >= 0; n--) {
        if (!visited[process[n]]) {
            dfs_reversed(process[n]);
            num_componentes++;
        }
    }

    adj_components.resize(num_componentes);
    num_coins_component.resize(num_componentes, 0);
    check.resize(num_componentes, vector<bool> (num_componentes, false));
    for (long long n = 0; n < num_nodos; n++) {
        num_coins_component[componente[n]] += num_coins[n];
        for (auto neigh : adj[n]) {
            if (componente[n] == componente[neigh]) continue;
            if (!check[componente[n]][componente[neigh]]) {
                check[componente[n]][componente[neigh]] = true;
                adj_components[componente[n]].push_back(componente[neigh]);
            }
        }
    }

    component_visited.resize(num_componentes, false);
    for (long long c = 0; c < num_componentes; c++) {
        if (!component_visited[c]) topsort(c);
    }

    long long ret = 0;
    long long actual_max;
    vector<long long> max_coins (num_componentes, -1);
    for (auto t : topsorted) {
        //cout << a << " ";
        actual_max = 0;
        for (auto n : adj_components[t]) {
            actual_max = max(actual_max, max_coins[n]);
        }
        max_coins[t] = num_coins_component[t] + actual_max;
        ret = max(ret, max_coins[t]);
    }

    cout << ret;
    // cout << endl << endl;
    // for (long long n = 0; n < num_componentes; n++) {
    //     cout << n << " --> ";
    //     for (auto a : adj_components[n]) cout << a << " ";
    //     cout << endl;
    // }




}