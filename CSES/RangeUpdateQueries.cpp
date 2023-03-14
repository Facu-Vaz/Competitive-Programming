#include <bits/stdc++.h>

using namespace std;
vector<long long> segTree;
vector<long long> num_list;
long long size_list, N, num_queries; 

void update (int a, int b, int x) 
{

}

int find (int a) 
{

}

int main ()
{
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
    int operation, a, b, x;
    vector<int> ret;
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