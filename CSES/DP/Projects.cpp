#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long

using namespace std;

ll num_projects;

struct proyecto {
    ll start;
    ll finish;
    ll extra;
};

bool sorting_func (proyecto a, proyecto b)
{
    return a.finish < b.finish;
}

vector<proyecto> projects;

ll binary_search (ll x, ll a, ll b)
{
    ll middle = (a + b) / 2; 
    //cout << a << " " << b << " - " << middle << " " << projects[middle].finish << endl;
    if (a == b) {
        return a;
    } else if (a+1 == b) {
        if (projects[b].finish < x) return b;
        return a;
    }
    if (projects[middle].finish < x) {
        return binary_search(x, middle, b);
    }
    else {
        return binary_search(x, a, middle);
    }
}

int main () 
{
    //ifstream cin("input.in");
    
    cin >> num_projects;
    projects.resize(num_projects+1);

    projects[0].extra = 0; projects[0].finish = 0;
    projects[0].start = 0; 

    for (int i = 1; i <= num_projects; i++) 
    {
        cin >> projects[i].start >> projects[i].finish >> projects[i].extra;
    }

    sort(projects.begin(), projects.end(), sorting_func);

    vector<ll> dp (projects.size(), 0);
    proyecto actual;
    for (int p = 1; p <= num_projects; p++)
    {
        //cout << p << " -> " << endl;
        actual = projects[p]; ll a = dp[binary_search(actual.start, 0, p)];
        dp[p] = max(a + actual.extra, dp[p-1]);
    }

    cout << dp[num_projects];

    //cout << dp.size() << endl;

    // cout << endl;
    // for (auto a : dp) cout << a << " ";
    // cout << endl;

    // for (auto p : projects)
    // {
    //     cout << p.start << " " << p.finish << " - " << p.extra << endl;
    // }
}