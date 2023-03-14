#include <bits/stdc++.h>

using namespace std;

vector<int> segTree; int INF = INT_MAX-100;
int list_size, num_queries, N;

int find (int a, int b) {
    a += N; b += N;
    int r = INF;
    while (a <= b) {
        if (a % 2 == 1) r = min(segTree[a++], r);
        if (b % 2 == 0) r = min(segTree[b--], r);
        a /= 2; b /= 2;
    }
    return r;
}

int main () 
{
    cin >> list_size >> num_queries;
    N = 1;
    while (N < list_size) N *= 2;  
    segTree.resize(N*2, INF);
    for (int i = 0; i < list_size; i++) cin >> segTree[i+N];
    for (int i = N-1; i >= 1; i--) {
        segTree[i] = min(segTree[i*2], segTree[i*2 + 1]);
    }
    vector<int> ret;
    int a, b;
    for (int q = 0; q < num_queries; q++) {
        cin >> a >> b; 
        ret.push_back(find(a-1, b-1));
    }
    for (auto r : ret) cout << r << endl;

}