#include <bits/stdc++.h>

using namespace std;

int N, num_coins;
int MOD = 1e9 + 7;
vector<int> coins;
vector<bool> done;
vector<int> DP;

int solve(int x) {
    if (done[x]) return DP[x];
    //cout << x << endl;
    int sum = 0;
    for (auto c : coins) {
        if (x - c >= 0) sum = (solve(x - c) + sum) % MOD;
        else break;
    }
    done[x] = true;
    DP[x] = sum;
    return sum;
}

int main () 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num_coins >> N;
    DP.resize(N+1, -1);
    done.resize(N+1, false);
    coins.resize(num_coins);
    DP[0] = 1; done[0] = true;
    for (int c = 0; c < num_coins; c++) {
        cin >> coins[c];
    }
    sort(coins.begin(), coins.end());
    int ret = solve(N);
    //for (auto r : DP) cout << r << " ";
    //cout << endl;
    cout << ret;
}