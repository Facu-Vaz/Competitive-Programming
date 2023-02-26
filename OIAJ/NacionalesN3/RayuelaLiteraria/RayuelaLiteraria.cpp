#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> sopa;
vector<vector<int>> puntajes;
int len, n;
vector<pair<int, int>> moves = {{1, 0},{0, -1},{-1, 0},{0, 1}};

int solve(string word)
{
    len = word.size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (n, vector<int> (len, 0)));
    int max_points = 0;
    int temp_max = 0;
    for (int l = 0; l < len; l++)
    {   
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sopa[i][j] == word[l]) 
                {
                    if (l == 0) dp[i][j][l] = puntajes[i][j];
                    else 
                    {
                        temp_max = 0;
                        for (auto move : moves)
                        {
                            if (i + move.first >= 0 && i + move.first < n && j + move.second >= 0 && j + move.second < n )
                            {
                                temp_max = max(dp[i+move.first][j+move.second][l-1], temp_max);
                            }
                        }
                        if (temp_max > 0) 
                        {
                            dp[i][j][l] = puntajes[i][j] + temp_max; 
                            if (l == len-1) max_points = max(max_points, dp[i][j][l]);
                        }
                    }
                }
                
            }
        }

        // for (auto a : dp)
        // {
        //     for (auto b : a)
        //     {
        //         cout << b[l] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    return max_points;
}

int main()
{
    ifstream ifs;
    ifs.open("rayuela.in");
    ofstream ofs;
    ofs.open("rayuela.out");

    int puntaje, num_palabras;
    char letra;
    ifs >> n >> num_palabras;
    sopa.resize(n, vector<char> (n));
    puntajes.resize(n, vector<int> (n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ifs >> letra >> puntaje;
            sopa[i][j] = letra;
            puntajes[i][j] = puntaje;
        }
    }

    string palabra;
    vector<int> ret;

    for (int p = 0; p < num_palabras; p++)
    {
        ifs >> palabra;
        ret.push_back(solve(palabra));
    }


    // for (auto a : sopa)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    // for (auto a : puntajes)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    for (auto r : ret)
    {
        ofs << r << endl;
    }




}