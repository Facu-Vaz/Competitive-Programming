#include <bits/stdc++.h>

using namespace std;

int num_hotels, num_groups, N;
vector<int> segTree;

int look_for (int x)
{
    if (segTree[1] < x) return 0;
    int p = 1; 
    while (p < N) {
        if (segTree[p*2] >= x) p = p*2;
        else p = p*2 + 1;
    }  
    int ret = p-N+1;
    segTree[p] -= x; p /= 2;
    while (p > 0) {
        segTree[p] = max(segTree[p*2], segTree[p*2+1]);
        p /= 2;
    }
    return ret;
}

int main ()
{
    cin >> num_hotels >> num_groups;
    N = 1;
    while (N < num_hotels) N *= 2;
    segTree.resize(N*2);
    for (int i = 0; i < num_hotels; i++) cin >> segTree[N+i];
    for (int i = N-1; i > 0; i--) segTree[i] = max(segTree[i*2], segTree[i*2+1]);

    // for (auto a : segTree) cout << a << " ";
    // cout << endl;

    int group; vector<int> ret;
    for (int i = 0; i < num_groups; i++)
    {
        cin >> group;
        ret.push_back(look_for(group));
    }

    for (auto r : ret) cout << r << " ";
    
}