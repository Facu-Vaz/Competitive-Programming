#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int H, W, start, end;
    cin >> H >> W;
    int num_nodes = 0;
    vector<vector<int>> adj;
    vector<vector<int>> id (H, vector<int> (W, -1));
    char temp;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cin >> temp;
            if (temp != '#') {
                id[h][w] = num_nodes; 
                adj.push_back(vector<int>());
                if (h > 0) {
                    if (id[--h][w] != -1) {
                        adj[num_nodes].push_back(id[--h][w]);
                        adj[id[--h][w]].push_back(num_nodes);
                    }
                } 
                if (w > 0) {
                    if (id[h][w-1] != -1) {
                        adj[num_nodes].push_back(id[h][--w]);
                        adj[id[h][--w]].push_back(num_nodes);
                    }
                }
                num_nodes++;
            }
        }
    }

    for (int a = 0; a < num_nodes; a++) {
        cout << a << " - ";
        for (auto b : adj[a]) {
            cout << b << " , ";
        }
    }
}