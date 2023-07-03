#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;

int num_ranges;
vector<pair<pair<int, int>, int>> ranges;
pair<int, int> single_range;

bool sort_ranges(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    else return a.first.second > b.first.second;
}

int main() {
    //ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_ranges; int a, b;
    ranges.resize(num_ranges);

    for (int r = 0; r < num_ranges; r++) {
        cin >> a >> b;
        ranges[r] = {{a, b}, r};
    }

    sort(ranges.begin(), ranges.end(), sort_ranges);

    vector<int> how_many_included (num_ranges);
    int id, actual_position, num_above_it;
    indexed_set s;
    map<int, int> how_many;
    auto iter = s.order_of_key({0, 0});
    for (auto r : ranges) {
        tie(single_range, id) = r; tie(a, b) = single_range;
        if (!how_many.count(b)) how_many[b] = INT_MAX;
        s.insert({b, how_many[b]}); actual_position = s.order_of_key({b, how_many[b]});
        how_many[b]--;
        num_above_it = s.size() - actual_position - 1;
        how_many_included[id] = num_above_it;
    }

    s.clear();
    vector<int> how_many_including (num_ranges);
    map<int, int> how_many_again;
    for (int r = ranges.size()-1; r >= 0; r--) {
        tie(single_range, id) = ranges[r]; tie(a, b) = single_range;
        if (!how_many_again.count(b)) how_many_again[b] = 1;
        s.insert({b, how_many_again[b]}); actual_position = s.order_of_key({b, how_many_again[b]});
        how_many_again[b]++;
        num_above_it = actual_position;
        how_many_including[id] = num_above_it;
    }

    // for (auto r : ranges) {
    //     cout << r.second << " - (" << r.first.first << ", " << r.first.second << ")" << endl;
    // }

    for (auto a : how_many_including) cout << a << " ";
    cout << endl;
    for (auto a : how_many_included) cout << a << " ";

}