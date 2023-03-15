#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<ll> segTree;
vector<ll> num_list;
ll size_list, N, num_queries; 

void update (ll a, ll b, ll x) 
{
    a += N; b += N;
    while (a <= b)
    {
        if (a % 2 == 1) segTree[a++] += x;
        if (b % 2 == 0) segTree[b--] += x;
        a /= 2; b /= 2;
    }
}

ll find (ll a) 
{
    a += N;
    ll sum = 0;
    while (a != 0) {
        sum += segTree[a];
        a /= 2;
    }
    return sum;
}

int main ()
{
    //ifstream cin("input.in");
    cin >> size_list >> num_queries;
    N = 1;
    while (N < size_list) {
        N *= 2;
    }
    segTree.resize(N*2, 0);
    num_list.resize(size_list);
    for (int i = 0; i < size_list; i++) {
        cin >> num_list[i];
    }
    long long operation, a, b, x;
    vector<ll> ret;
    for (int q = 0; q < num_queries; q++)
    {
        cin >> operation;
        if (operation == 1) {
            cin >> a >> b >> x;
            a--; b--;
            update(a, b, x);
        }
        if (operation == 2) {
            cin >> a;
            a--;
            ret.push_back(find(a) + num_list[a]);
        }
    }
    for (auto a : ret) cout << a << endl;

}