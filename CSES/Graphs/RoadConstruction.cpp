#include <bits/stdc++.h>

using namespace std;

int num_nodes, num_days;
vector<int> group;
vector<int> father;

int find (int x)
{
    while (father[x] != x) x = father[x];
    return x;
}

int join (int a, int b)
{
    a = find(a);
    b = find(b);
    //cout << a << " " << a_father << " - " << b << " " << b_father <<  endl;
    if (a == b) return -1;
    if (group[b] > group[a]) swap(a, b);
    father[b] = a; 
    group[a] += group[b];
    return group[a];
}

int main() 
{
    cin >> num_nodes >> num_days;
    group.resize(num_nodes+1, 1);
    father.resize(num_nodes+1);
    for (int n = 1; n <= num_nodes; n++) father[n] = n;

    int modules_num = num_nodes;
    int max_module = 1;

    vector<pair<int, int>> ret;
    int a, b, result;
    for (int d = 0; d < num_days; d++)
    {
        cin >> a >> b;
        result = join(a, b);
        if (result != -1) {
            modules_num--;
            max_module = max(max_module, result);
        }
        //cout << result << endl;
        ret.push_back({modules_num, max_module});
    }

    for (auto r : ret) cout << r.first << " " << r.second << endl;
}