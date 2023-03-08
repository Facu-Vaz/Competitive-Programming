#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
int cities_num, conexions_num, a, b, stop_in;
vector<int> trip;
vector<bool> in_trip;
vector<bool> visited;

bool dfs (int x, int f) {
    trip.push_back(x);
    if (in_trip[x]) return true;
    bool keep = false;
    in_trip[x] = true;
    for (auto a : adj[x]) {
        if (in_trip[a] && a != f) {
            trip.push_back(a); return true;
        }
        if (!visited[a] && a != f) {
            keep = dfs(a, x);
            visited[a] = true;
            if (keep) break;
        }
    }
    if (keep) {
        return true;
    }
    trip.pop_back(); in_trip[x] = false;
    return false;
}

int main () {
    //ifstream cin("input.in");

    cin >> cities_num >> conexions_num;
    adj.resize(cities_num+1);

    for (int c = 0; c < conexions_num; c++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.resize(cities_num+1, false);
    in_trip.resize(cities_num+1, false);

    bool done = false;
    for (int n = 1; n <= cities_num; n++) {
        if (!visited[n]) {
            visited[n] = true;
            done = dfs(n, -1);
        }
        if (done) break;
    }

    //cout << "|" << in_trip.size() << "|" << endl;
    // for (auto a : trip) cout << a << " ";
    // cout << endl;


    if (!done) cout << "IMPOSSIBLE";
    else {
        vector<int> ret; 
        int end = trip[trip.size()-1]; ret.push_back(end);
        int i = trip.size()-2;
        while (trip[i] != end) {
            ret.push_back(trip[i]); i--;
        }
        ret.push_back(trip[i]);



        cout << ret.size() << endl;
        for (auto a : ret) cout << a << " ";
    }

}