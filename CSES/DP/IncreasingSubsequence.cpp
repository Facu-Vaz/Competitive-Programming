#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;

int main ()
{
    cin >> N; int temp;
    vector<int> LIS;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        auto p = lower_bound(LIS.begin(), LIS.end(), temp);
        if (p == LIS.end()) LIS.push_back(temp);
        else LIS[p - LIS.begin()] = temp;
    }
    cout << LIS.size();
}