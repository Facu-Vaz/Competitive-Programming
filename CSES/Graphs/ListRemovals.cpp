#include <bits/stdc++.h>

using namespace std;

vector<int> segTree;
vector<int> number_list;
int list_len, N;


int remove (int x)
{
    int sum = 0; int ret;
    int p = 1;
    while (p < N) {
        if (sum + segTree[p*2] < x) {
            sum += segTree[p*2];
            p = p*2 + 1;
        }
        else {
            p = p*2;
        }
    }    
    ret = p - N;
    segTree[p] = 0; p /= 2;
    while (p > 0) {
        segTree[p] = segTree[p*2] + segTree[p*2+1]; p /= 2;
    }
    return number_list[ret];
}

int main ()
{
    cin >> list_len;
    N = 1;
    while (N < list_len) N *= 2;

    number_list.resize(list_len);
    for (int i = 0; i < list_len; i++) cin >> number_list[i];

    segTree.resize(N*2, 0);
    for (int i = 0; i < list_len; i++) segTree[N+i] = 1;
    for (int i = N-1; i > 0; i--) segTree[i] = segTree[i*2] + segTree[i*2 + 1];

    // for (auto a : segTree) cout << a << " ";   

    int which_remove;
    int removed;
    // removed = remove(1);
    // cout << endl << removed << endl;
    // for (auto a : segTree) cout << a << " ";   

    vector<int> dev;
    for (int r = 0; r < list_len; r++)
    {
        cin >> which_remove;
        removed = remove(which_remove);
        dev.push_back(removed);
    }

    for (auto r : dev) cout << r << " ";
}