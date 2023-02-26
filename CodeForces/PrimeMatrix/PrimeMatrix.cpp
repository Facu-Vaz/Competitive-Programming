#include <bits/stdc++.h>

using namespace std;
int H, W, actual, ret, temp, closest;
int INF = INT_MAX - 10;
vector<int> primes {2};

void is_prime(int x)
{
    bool prime = true; 
    for (auto a : primes)
    {
        if (a*a > x) break;
        if (x % a == 0) {
            prime = false; break;
        }
    }
    if (prime) primes.push_back(x);    
}

int main ()
{
    for (int i = 3; i < 1e5+1e4; i++) is_prime(i);
    

    cin >> H >> W;
    ret = INF;
    vector<int> columns (W, 0);
    for (int h = 0; h < H; h++)
    {
        temp = 0;
        for (int w = 0; w < W; w++)
        {
            cin >> actual;
            auto upper = lower_bound(primes.begin(), primes.end(), actual);
            closest = primes[(upper - primes.begin())];
            if (closest != actual) {
                temp += closest - actual;
                columns[w] += closest - actual;
            }
            if (w == W-1) ret = min(temp, ret);
            //cout << primes[(upper - primes.begin())] - actual << " "; 
        }
       // cout << endl;
    }
    for (auto a : columns) ret = min(ret, a); 
    cout << ret;
}