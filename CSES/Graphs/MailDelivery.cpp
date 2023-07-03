#include <bits/stdc++.h>

using namespace std;

vector<int> father;
vector<int> num_children;

vector<vector<int>> adj;
vector<vector<bool>> path_done;
vector<int> num_entrances;
vector<int> ret;
vector<pair<int, int>> conections;

int num_nodes, num_paths, num_paths_done, global_start;

int find (int x) {
    while (father[x] != x) x = father[x];
    return x;
}

void join (int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (num_children[b] > num_children[a]) swap(a, b);
    father[b] = a;
    num_children[a] += num_children[b];
}

int dfs (int x) {
    //cout << x << " - " << num_paths_done;
    int a, b; 
    int sum = 0;
    for (auto n : adj[x]) {
        a = n; b = x;
        if (a > b) swap(a, b);
        if (!path_done[a][b]) {
            path_done[a][b] = true;
            ret.push_back(n);
            if (n == global_start) {
                //cout << " A" << endl;
                //cout << "HEYY";
                return 1;
            }
            else {
                //cout << " B" << endl;
                return dfs(n)+1;
            }
        }
    }

}

int main() {
    ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_nodes >> num_paths;

    num_children.resize(num_nodes, 1);
    father.resize(num_nodes);
    conections.resize(num_paths);
    for (int n = 0; n < num_nodes; n++) father[n] = n;

    adj.resize(num_nodes);
    num_entrances.resize(num_nodes, 0);
    path_done.resize(num_nodes, vector<bool> (num_nodes, false));

    int a, b;
    for (int p = 0; p < num_paths; p++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); num_entrances[a]++;
        adj[b].push_back(a); num_entrances[b]++;
        join(a, b);
        conections[p] = {a, b};

    }

    bool possible = true;
    tie(a, b) = conections[0];
    int common_group = find(a);
    for (int p = 1; p < num_paths; p++) {
        tie(a, b) = conections[p];
        if (find(a) != common_group) {
            possible = false; break;
        }
    }

    for (auto a : num_entrances) {
        if (a % 2 != 0) {
            possible = false; break;
        }
    }

    if (num_entrances[0] == 0) possible = false;

    //for (int i = 0; i < num_nodes; i++) cout << i << " - " << num_children[find(i)] << endl;

    if (!possible) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    // for (auto a : num_entrances) cout << a << " ";
    // cout << endl;

    ret.push_back(0);
    vector<int> backup;
    num_paths_done = 0;
    int point; bool keep; int node, temp;
    while (num_paths_done < num_paths) {
        point = ret.size()-1;
        keep = true;
        while (keep) {
            node = ret[point];
            temp = node;
            //cout << num_paths_done << "- " << node << endl;
            for (auto n : adj[node]) {
                if (temp > n) swap(temp, n);
                if (!path_done[temp][n]) {
                    global_start = node;
                    num_paths_done += dfs(node);
                    //cout << endl << "-------------------  " << num_paths_done << endl;
                    keep = false; break;
                } 
            }
            point--;
            if (point == -1) {
                keep = false; break;
            }
            backup.push_back(node); ret.pop_back();
        }
    }  

    //for (auto a : ret) cout << a+1 << " ";
    //cout << endl;
    for (auto i : ret) cout << i+1 << " ";
    for (int i = backup.size()-1; i >= 0; i--) cout << backup[i]+1 << " ";

    return 0;


}