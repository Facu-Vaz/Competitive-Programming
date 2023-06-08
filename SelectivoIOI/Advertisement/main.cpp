#include <bits/stdc++.h>
#define ll long long

// #define all(x) (a.begin(), a.end())

using namespace std;

ll N, height, id;
vector<pair<ll, ll>> ads;
set<ll> processed;
vector<ll> pendent;

int main()
{   
    //ifstream cin("input.in");
    cin >> N;
    ads.resize(N);

    ll ret = -1;

    for (ll i = 0; i < N; i++) {
        cin >> height;
        ads[i] = {height, i};
    }

    sort(ads.begin(), ads.end());

    ll a, b;
    ll previous = ads[0].first;

    for (auto ad : ads) {
        tie(height, id) = ad;

        // if (previous != height) {
        //     for (auto pen : pendent) processed.insert(pen);
        //     previous = height;
        //     pendent.clear();
        //     pendent.push_back(id);
        // } else pendent.push_back(id);

        //cout << height << " " << id << "  -  ";
        auto it_right = upper_bound(processed.begin(), processed.end(), id);
        if (it_right == processed.end()) b = N;
        else b = *it_right;
        
        if (it_right == processed.begin()) a = 0;
        else {
            auto it_left = prev(it_right);  
            a = *it_left + 1;
        }
        //cout << "B";
        //cout << a << " " << b << " " << height << "  -  ";
        //cout << (b - a) * height << endl;
        processed.insert(id);
        ret = max(ret, (b - a) * height);
    }

    cout << ret;

}