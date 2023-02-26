#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> dp;
int INF = INT_MAX-10;

int cost (char a, char b)
{
    return (a == b) ? 0 : 1;
}

int main()
{
    ifstream cin("adn.in");
    ofstream ofs("adn.out");
    int B_len, A_len, max_mutaciones, limit, bias, actual, c;
    string A_cadena, B_cadena;
    cin >> A_len >> B_len >> max_mutaciones;
    if (A_len < B_len) {
        swap(A_len, B_len);
        cin >> B_cadena >> A_cadena;
    }
    else cin >> A_cadena >> B_cadena;
    if (abs(A_len - B_len) > max_mutaciones) cout << "Muy distintas.";

    dp.resize(B_len+1, vector<int> (max_mutaciones*2 + 1, INF));

    for (int a = 0; a < max_mutaciones*2+1; a++) dp[0][a] = a;

    for (int b = 1; b < B_len+1; b++)
    {
        bias = (b <= max_mutaciones) ? 0 : (b - max_mutaciones);
        limit = min(bias+(max_mutaciones*2+1), A_len+1);
        //cout << b << " - " << bias << " - " << limit << " -";
        for (int a = bias; a < limit; a++) 
        {
            //cout << " " << a;
            if (a-bias > 0) {
                actual = dp[b][a-bias-1] + 1;
                c = cost(A_cadena[a-1], B_cadena[b-1]);
                if (bias == 0) actual = min(dp[b-1][a-bias-1] + c, actual);
                else actual = min(dp[b-1][a-bias] + c, actual);

                if (a-bias != max_mutaciones*2 || bias == 0) {
                    if (bias == 0) actual = min(dp[b-1][a-bias] + 1, actual);
                    else actual = min(dp[b-1][a-bias+1] + 1, actual);
                }
            }
            else if (a-bias != max_mutaciones*2 || bias == 0) {
                if (bias == 0) actual = dp[b-1][a-bias] + 1;
                else actual = dp[b-1][a-bias+1] + 1;
            }

            dp[b][a-bias] = actual;

        }
    }

    if (actual > max_mutaciones) ofs << "Muy distintas.";
    else ofs << actual;


}