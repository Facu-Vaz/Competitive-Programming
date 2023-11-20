#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> segTree;
ll N;

void remove(ll x) {
    x += N;
    segTree[x] = 0; x /= 2;
    while (x != 0)
    {
        segTree[x] = segTree[x*2] +segTree[(x*2)+1]; 
        x /= 2;
    }
}

ll sum(ll a, ll b) {
    a += N; b += N;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += segTree[a++];
        if (b % 2 == 0) s += segTree[b--];
        a /= 2; b /= 2;
    }
    return s-1;
}

long long plantas(vector<int> &h) {
    N = 1;
    while (N < h.size()) N <<= 1; 
    segTree.resize(N*2, 0);
    for (ll i = N; i < h.size()+N; i++) {
        segTree[i] = 1;
    }
    for (ll i = N-1; i > 0; i--) {
        segTree[i] = segTree[i*2] + segTree[(i*2)+1];
    }
    vector<pair<ll, ll>> lista_plantas;
    for (ll i = 0; i < h.size(); i++) {
        lista_plantas.push_back({h[i], i});
    }
    sort(lista_plantas.begin(), lista_plantas.end());

    ll ret = 0;
    ll dis;
    for (auto p : lista_plantas) {
        

        dis = sum(0, p.second);
        ret += min(dis, segTree[1]-dis-1);

        remove(p.second);

        // cout << ret << "   " << dis << " - " << segTree[1]-dis-1  << " - " << segTree[1] << endl;
        // cout << "Alt " << p.first << " - Ind " << p.second << " - Dis " << min(dis, segTree[1]-dis-1) << endl; 
    }
    
    return ret;
}
