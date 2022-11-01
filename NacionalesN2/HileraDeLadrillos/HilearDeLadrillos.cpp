#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int num_valores = 0;
    cin >> n;
    vector<string> ladrillos (n);
    for (int l = 0; l < n; l++)
    {
        cin >> ladrillos[l];
        if (ladrillos[l] != "*") num_valores++;
    }

    for (auto l : ladrillos)
    {

    }

    cout << num_valores;
}