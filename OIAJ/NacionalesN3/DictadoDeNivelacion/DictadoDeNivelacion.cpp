#include <string>
#include <bits/stdc++.h>

using namespace std;

int  nivelacion( string palabra )
{
    int l = palabra.size();
    vector<vector<int>> dp (l, vector<int> (l));

    for (int j = 1; j < l; j++)
    {
        for (int i = j-1; i >= 0; i--)
        {
            dp[i][j] = palabra[i] == palabra[j] ? dp[i+1][j-1] : min(dp[i+1][j], dp[i][j-1]) + 1;
        }
    }

    return dp[0][l-1];

}
