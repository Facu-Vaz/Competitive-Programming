#include <bits/stdc++.h>

using namespace std;

int main () {
    int num_computers, num_conexions, a, b;
    cin >> num_computers >> num_conexions;
    vector<vector<int>> adj (num_computers+1, vector<int>());
    vector<int> father(num_computers+1, -1);

    for (int c = 0; c < num_conexions; c++) {
        cin >> a >> b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q; q.push(1); bool done = false;
    int actual;
    father[1] = -2;
    while (!q.empty() && !done) {
        actual = q.front(); q.pop();
        if (actual == num_computers) {
            done = true; continue;
        } 
        for (auto n : adj[actual]) {
            if (father[n] == -1) {
                father[n] = actual;
                q.push(n);
            }
        }
    }

    if (!done) cout << "IMPOSSIBLE";
    else {
        int path = num_computers; vector<int> ret;
        while (path != -2) {
            ret.push_back(path);
            path = father[path];
        }
        cout << ret.size() << endl;
        reverse(ret.begin(), ret.end());
        for (auto a : ret) cout << a << " ";
    }

}