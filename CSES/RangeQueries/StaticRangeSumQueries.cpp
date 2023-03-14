#include <bits/stdc++.h>

using namespace std;

long long N, Q, temp;
vector<long long> sum_list;

int main ()
{
    cin >> N >> Q;
    sum_list.resize(N+1, 0);
    for (long long n = 1; n <= N; n++) {
        cin >> temp;
        sum_list[n] = sum_list[n-1] + temp; 
    }
    vector<long long> ret; long long a, b;
    for (long long q = 0; q < Q; q++) {
        cin >> a >> b;
        ret.push_back(sum_list[b] - sum_list[a-1]);
    }
    for (auto r : ret) cout << r << endl;
}