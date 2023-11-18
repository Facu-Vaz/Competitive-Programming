#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll num_queries, a, b, num_nodes;

void add(vector<tuple<bool, ll, ll, ll>> &dp) 
{
    ll father, k;
    cin >> father >> k; father--;
    num_nodes++;
    ll x = num_nodes; 
    bool father_pos;
    ll f_racha, f_best_pos, f_best_neg;
    tie(father_pos, f_racha, f_best_pos, f_best_neg) = dp[father];
    
    bool is_pos;
    ll racha, best_pos, best_neg;
    if (k == 1) {
        if (father_pos) racha = f_racha+1;
        else racha = 1;
        best_pos = max(racha, f_best_pos);
        dp.push_back({true, racha, best_pos, f_best_neg});
        // cout << "ADDED: " << x << " : (" << true << ", " << racha << ", " << best_pos << ", " << f_best_neg << ")" << endl;
    }

    if (k == -1) {
        if (!father_pos) racha = f_racha+1;
        else racha = 1;
        best_neg = max(racha, f_best_neg);
        dp.push_back({false, racha, f_best_pos, best_neg});
        // cout << "ADDED: " << x << " : (" << false << ", " << racha << ", " << f_best_pos << ", " << best_neg << ")" << endl;
    }

    
}

ll query(vector<tuple<bool, ll, ll, ll>> &dp)
{
    ll a, b, k;
    cin >> a >> b >> k;
    a--; b--;

    if (a == b) {
        if (k == 1 || k == 0) return 1;
        return 0;
    }

    bool is_pos;
    ll racha, best_pos, best_neg;
    tie(is_pos, racha, best_pos, best_neg) = dp[b];

    if (k == 0) {
        if (best_pos > 0 && best_neg > 0) return 1;
        return 0;
    }

    if (k > 0) {
        if (best_pos >= k) return 1;
        return 0;
    }

    if (k < 0) {
        if (best_neg >= abs(k)) return 1;
        return 0;
    }
}

void solve(vector<ll> &ret) 
{
    cin >> num_queries;
    num_nodes = 0;
    char q_type;
    ll res;
    vector<tuple<bool, ll, ll, ll>> dp;
    dp.push_back({true, 1, 1, 0});
    for (ll q = 0; q < num_queries; q++) {
        cin >> q_type;
        if (q_type == '+') add(dp);
        else if (q_type == '?') ret.push_back(query(dp));
    }
    
}

int main()
{
    ll num_cases;
    vector<ll> ret;
    cin >> num_cases;
    for (ll c = 0; c < num_cases; c++) solve(ret);

    for (auto r : ret) cout << (r == 1 ? "YES" : "NO") << endl;
}