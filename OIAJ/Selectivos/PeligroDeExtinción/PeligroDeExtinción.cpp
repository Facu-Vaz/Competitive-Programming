#include <bits/stdc++.h>

using namespace std;

int H, W, num_pozos;
vector<vector<int>> biggest_box;
vector<vector<bool>> pozos_location;
vector<vector<int>> biggest_in_range;

int main () {
    ifstream cin("yurumi.in");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W >> num_pozos;

    biggest_box.resize(H+1, vector<int> (W+1,0));
    pozos_location.resize(H+1, vector<bool> (W+1,false));
    biggest_in_range.resize(H+1, vector<int> (W+1,0));

    int x, y;
    for (int p = 0; p < num_pozos; p++) {
        cin >> y >> x;
        pozos_location[y][x] = true;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (pozos_location[i][j]) biggest_box[i][j] = 0;
            else biggest_box[i][j] = min(biggest_box[i-1][j-1], min(biggest_box[i-1][j], biggest_box[i][j-1])) + 1;
            biggest_in_range[i][j] = max(biggest_box[i][j], max(biggest_in_range[i-1][j], biggest_in_range[i][j-1]));
        }
    }

    cout << "\n\n";
    for (auto a : biggest_box)
    {
        for (auto b : a) cout << b << " ";
        cout << "\n";
    }
    cout << "\n\n";
    for (auto a : biggest_in_range)
    {
        for (auto b : a) cout << b << " ";
        cout << "\n";
    }

}