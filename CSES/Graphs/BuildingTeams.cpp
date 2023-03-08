#include <bits/stdc++.h>

using namespace std;

vector<int> team;
vector<vector<int>> adj;

bool bfs (int x) {
    team[x] = 1; 
    bool posible = true; int pupil_actual, team_actual;
    queue<pair<int, int>> q; q.push({x, 1});

    while (!q.empty() && posible) {
        tie(pupil_actual, team_actual) = q.front(); q.pop();

        for (auto a : adj[pupil_actual]) {
            if (team[a] == 0) {
                if (team_actual == 1) team[a] = 2;
                else if (team_actual == 2) team[a] = 1;
                q.push({a, team[a]});
            }
            else if (team[a] == team_actual) {
                posible = false; break;
            }
        }
    }

    if (!posible) return false;
    return true;
}

int main () {
    int num_pupils, num_friendships, a, b;

    cin >> num_pupils >> num_friendships;

    adj.resize(num_pupils+1);
    team.resize(num_pupils+1, 0);

    for (int f = 0; f < num_friendships; f++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool posible = true;
    for (int p = 1; p <= num_pupils; p++) {
        if (team[p] == 0) posible = bfs(p);
        if (!posible) break;
    }

    if (!posible) cout << "IMPOSSIBLE";
    else {
        for (int p = 1; p <= num_pupils; p++) cout << team[p] << " ";
    }
}