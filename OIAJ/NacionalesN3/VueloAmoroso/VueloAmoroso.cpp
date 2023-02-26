#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

int main()
{
    ifstream cin("vuelo.in");
    ofstream cout("vuelo.out");
    
    int largo_viaje;
    int max_altura = 0;
    cin >> largo_viaje;
    vector<int> altura_pajara (largo_viaje+1, 0);

    for (int i = 1; i <= largo_viaje; i++) 
    {
        cin >> altura_pajara[i];
        max_altura = max(max_altura, altura_pajara[i]);
    }

    vector<vector<int>> dp (max_altura+2, vector<int> (largo_viaje+1, INF));
    dp[0][0] = 0;

    vector<vector<int>> path (max_altura+1, vector<int> (largo_viaje+1, -1));
    int from, minimum;
    for (int s = 1; s <= largo_viaje; s++)
    {
        for (int h = 1; h <= max_altura; h++)
        {
            if (dp[h-1][s-1] < dp[h+1][s-1]){
                from = h-1; minimum = dp[h-1][s-1];
            }
            else{
                from = h+1; minimum = dp[h+1][s-1];
            }
            path[h][s] = from;
            if (minimum == INF) dp[h][s] = INF;
            else dp[h][s] = minimum + abs(h - altura_pajara[s]);
        }
    }
    int altura_final = 1;
    int min_gasto = dp[1][largo_viaje];
    for (int i = 2; i <= max_altura; i++)
    {
        if (dp[i][largo_viaje] < min_gasto)
        {
            min_gasto = dp[i][largo_viaje]; altura_final = i;
        }
    }
    cout << min_gasto << endl;

    vector<int> ret;
    int i = largo_viaje;
    while (altura_final != -1)
    {
        ret.push_back(altura_final);
        altura_final = path[altura_final][i--];
    }
    ret.pop_back();
    reverse(ret.begin(), ret.end());

    for (int r : ret)
    {
        cout << r << endl;
    }

    return 0;
}