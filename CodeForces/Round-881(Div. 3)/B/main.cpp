#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> solve() 
{
    ll lista_size, lista_item;
    cin >> lista_size;
    vector<ll> lista(lista_size);
    ll num_op = 0;
    ll total = 0;
    bool neg = false;
    for (ll i = 0; i < lista_size; i++) {
        cin >> lista_item;
        total += abs(lista_item);
        if (lista_item < 0) neg = true;
        else if (lista_item != 0 && neg) {
            neg = false;
            num_op += 1;
        }
    }
    if (neg) num_op += 1;

    return {total, num_op};
}

int main() 
{
    ll num_times;
    cin >> num_times;
    vector<pair<ll, ll>> ret;
    for (ll i = 0; i < num_times; i++) ret.push_back(solve());

    for (auto r : ret) cout << r.first << " " << r.second << endl;
}