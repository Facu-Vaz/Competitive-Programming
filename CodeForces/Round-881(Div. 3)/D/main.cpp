#include <bits/stdc++.h>
#define ll long long
using namespace std;

void leaves(vector<vector<ll>> &adj, vector<ll> &exits, ll x, ll father)
{
    ll neig = 0;
    for (auto n : adj[x])
    {
        if (n == father) continue;
        neig++;
        leaves(adj, exits, n, x);
        exits[x] += exits[n];
    }
    if (neig == 0) {
        exits[x] = 1;
        // cout << "AAA" << x << "  ";
    }
}

void solve(vector<ll> &ret) 
{
    // cout << "SOLVING" << endl;
    ll num_nodes, a, b;
    cin >> num_nodes;
    vector<vector<ll>> adj;
    adj.resize(num_nodes);
    vector<ll> exits;
    exits.resize(num_nodes);
    for (ll e = 1; e < num_nodes; e++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    leaves(adj, exits, 0, -1);

    ll num_asump;
    cin >> num_asump;
    for (ll i = 0; i < num_asump; i++) {
        cin >> a >> b; a--; b--;
        ret.push_back(exits[a] * exits[b]);
    }
}

int main()
{
    ll num_cases;
    vector<ll> ret;
    cin >> num_cases;
    for (ll c = 0; c < num_cases; c++) solve(ret);

    for (auto r : ret) cout << r << endl;
}