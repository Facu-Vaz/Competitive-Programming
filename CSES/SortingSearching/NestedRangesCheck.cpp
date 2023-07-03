#include <bits/stdc++.h>

using namespace std;

vector<bool> is_included;
vector<bool> is_including;

vector<pair<pair<int, int>, int>> ranges;

int num_ranges;

bool sort_func(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    else return a.first.second > b.first.second ;
}

int main() {
    //ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_ranges;
    is_included.resize(num_ranges, false);
    is_including.resize(num_ranges, false);
    ranges.resize(num_ranges);
    
    int a, b, id;
    pair<int, int> range;
    for (int r = 0; r < num_ranges; r++) {
        cin >> a >> b; ranges[r] = {{a, b}, r};
    }

    sort(ranges.begin(), ranges.end(), sort_func);

    int limit = -1;
    for (int r = 0; r < num_ranges; r++) {
        tie(range, id) = ranges[r]; tie(a, b) = range;
        if (b <= limit) {
            is_included[id] = true;
        } else {
            limit = b;
        }
    }

    limit = INT_MAX;
    for (int r = num_ranges-1; r >= 0; r--) {
        tie(range, id) = ranges[r]; tie(a, b) = range;
        if (b >= limit) {
            is_including[id] = true;
        } else {
            limit = b;
        }
    }


    // for (auto r : ranges) {
    //     tie(range, id) = r; tie(a, b) = range;
    //     cout << id << " - " << "(" << a << ", " << b << ")" << endl;
    // }

    for (auto a : is_including) cout << a << " ";
    cout << endl;
    for (auto a : is_included) cout << a << " ";

}