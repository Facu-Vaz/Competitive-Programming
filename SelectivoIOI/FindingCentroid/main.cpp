#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> num_children;
int num_nodes, num_con, half;
int centroid, temp;

int measure(int x, int father) 
{
    int children = 1;
    // cout << x << endl;
    for (auto n : adj[x]) {
        if (n == father) continue;
        children += measure(n, x);
    }
    num_children[x] = children;
    return children;
}

int find_centroid(int x, int father) {
    // cout << x+1 << endl;
    for (auto n : adj[x]) {
        if (n == father) continue;
        if (num_children[n] > half) {
            temp = num_children[n];
            num_children[n] = num_children[x];
            num_children[x] =- temp;
            return find_centroid(n, x);
        }
    }
    return x;
}

int main()
{
    // ifstream cin("input.in");

    cin >> num_nodes;
    half = num_nodes / 2;
    adj.resize(num_nodes);
    num_children.resize(num_nodes);
    int a, b;
    for (int i = 1; i < num_nodes; i++)
    {
        cin >> a >> b; a--; b--;
        // cout << a << " " << b << endl;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // for (int n = 0; n < num_nodes; n++) {
    //     cout << n+1 << " : ";
    //     for (auto a : adj[n]) cout << a+1 << ", ";
    //     cout << endl;
    // }

    measure(0, -1);

    centroid = find_centroid(0, -1);

    cout << centroid+1 << endl;
    
    // for (int i = 0; i < num_nodes; i++) cout << i << " " << num_children[i] << endl;
}