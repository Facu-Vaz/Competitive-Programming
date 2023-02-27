#include <bits/stdc++.h>

using namespace std;

int main ()
{
    //ifstream cin("input.in");

    int H, W, start, end;
    cin >> H >> W;
    int num_nodes = 0;
    vector<vector<int>> adj;
    vector<char> id (H*W, ' ');
    vector<char> movement (H*W, ' ');
    char temp;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cin >> id[h*W + w];
            if (id[h*W + w] == 'A') start = h*W + w;
            else if (id[h*W + w] == 'B') end = h*W + w;
        }
    }

    queue<int> q; q.push(start); bool done = false;
    int current; movement[start] = '-';
    while (!q.empty() && !done)
    {
        current = q.front(); q.pop();
        if (current == end) {
            done = true; continue;
        }
        if (current >= W) {
            if (movement[current-W] == ' ' && id[current-W] != '#') {
                movement[current-W] = 'U'; q.push(current-W);
            }
        }
        if (current < (H-1)*W) {
            if (movement[current+W] == ' ' && id[current+W] != '#') {
                movement[current+W] = 'D'; q.push(current+W);
            }
        }
        if (current % W != 0) {
            if (movement[current-1] == ' ' && id[current-1] != '#') {
                movement[current-1] = 'L'; q.push(current-1);
            }
        }
        if (current % W != W-1) {
            if (movement[current+1] == ' ' && id[current+1] != '#') {
                movement[current+1] = 'R'; q.push(current+1);
            }
        }
    }

    if (!done) cout << "NO";
    else {
        cout << "YES" << endl;
        vector<char> ret; char last_move = movement[end];
        int p = end;
        while (last_move != '-') {
            ret.push_back(last_move);
            if (last_move == 'R') p = p-1;
            if (last_move == 'L') p = p+1;
            if (last_move == 'U') p = p+W;
            if (last_move == 'D') p = p-W;
                 
            last_move = movement[p];
        }

        cout << ret.size() << endl; reverse(ret.begin(), ret.end());
        for (auto a : ret) cout << a;
    }
    
    

    //cout << start << endl << end;
}