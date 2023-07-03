#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;

int num_children, num_skiped;

int main() {
    //ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_children >> num_skiped;

    vector<int> ret;
    indexed_set s;

    for (int i = 1; i <= num_children; i++) s.insert(i);
    int index = 0; int actual_child;
    for (int i = 1; i <= num_children; i++) {
        index = (index+num_skiped) % s.size();
        actual_child = *s.find_by_order(index);
        ret.push_back(actual_child);
        s.erase(actual_child);
    }
    
    for (auto r : ret) cout << r << " ";
    

}