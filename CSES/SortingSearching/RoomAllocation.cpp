#include <bits/stdc++.h>

using namespace std;

long long num_costumers;
vector<pair<pair<long long, long long>, long long>> costumers;
vector<long long> room_of_costumer;

int main() {
    //ifstream cin("input.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num_costumers;
    costumers.resize(num_costumers);
    room_of_costumer.resize(num_costumers);
    long long a, b, id;
    for (long long c = 0; c < num_costumers; c++) {
        cin >> a >> b;
        costumers[c] = {{a, b}, c};
    }

    sort(costumers.begin(), costumers.end());

    pair<long long, long long> range;
    
    vector<long long> rooms = {costumers[0].first.second};
    room_of_costumer[0] = 0;

    // for (auto r : rooms) cout << r << " ";
    // cout << endl;
    long long total_rooms = 1;
    vector<long long>::iterator iter; long long index;
    for (long long c = 1; c < num_costumers; c++) {
        tie(range, id) = costumers[c]; tie(a, b) = range;
        iter = lower_bound(rooms.begin(), rooms.end(), a);
        index = (iter - rooms.begin());
        // cout << "(" << a << ", " << b << ")" << endl;
        // for (auto r : rooms) cout << r << " ";
        // cout << endl;
        // cout << index << endl;
        // cout << endl << endl;
        index--;
        if (index < 0) {
            rooms.push_back(b);
            room_of_costumer[id] = total_rooms;
            total_rooms++;
        }
        else {
            rooms[index] = b;
            room_of_costumer[id] = index;
        }
        // if (index < rooms.size()) {
        //     cout << "AA"; 
        // }
    }

    // for (auto c : costumers) {
    //     tie(range, id) = c; tie(a, b) = range;
    //     cout << id << " - (" << a << ", " << b << ")" << endl; 
    // }

    cout << total_rooms << endl;
    for (auto a : room_of_costumer) cout << a+1 << " ";
}