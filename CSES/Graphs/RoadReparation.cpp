#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll num_nodes, num_conexions;

vector<ll> father;
vector<ll> num_children;

ll find (ll x) {
    while (father[x] != x) x = father[x];
    return x;
}

bool unite (ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (num_children[a] < num_children[b]) swap(a, b);
    father[b] = a; num_children[a] += num_children[b];
    return true;
}

int main () {
    //ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_nodes >> num_conexions;

    num_children.resize(num_nodes+1, 1);
    father.resize(num_nodes+1, 0);
    for (int i = 1; i <= num_nodes; i++) father[i] = i;
    
    vector<pair<ll, pair<ll, ll>>> conexions;
    conexions.resize(num_conexions);
    ll a, b, cost;
    for (int c = 0; c < num_conexions; c++) {
        cin >> a >> b >> cost;
        conexions[c].first = cost;
        conexions[c].second = {a, b};
    }
    sort(conexions.begin(), conexions.end());

    ll ret = 0;
    for (auto a : conexions) {
        //cout << a.second.first << " " << a.second.second << " - " << a.first << endl;
        if (unite(a.second.first, a.second.second)) ret += a.first; 
    }

    bool possible = false;
    for (int n = 1; n <= num_nodes; n++) {
        if (num_children[n] == num_nodes) {
            possible = true; break;
        }
    }
    if (!possible) cout << "IMPOSSIBLE";
    else cout << ret;


}