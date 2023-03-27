#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tablita_frutales;
vector<vector<int>> tablita_pinos;
vector<vector<bool>> is_pino;
vector<vector<bool>> is_frutal;
vector<vector<int>> max_lado;
vector<vector<int>> max_frutales;

int H, W, num_pinos, num_frutales;

int main ()
{
    ifstream cin("frutales.in");
    ofstream cout("frutales.out");
    
    cin >> W >> H >> num_pinos >> num_frutales;
    tablita_frutales.resize(H+1, vector<int> (W+1, 0));
    tablita_pinos.resize(H+1, vector<int> (W+1, 0));
    is_frutal.resize(H+1, vector<bool> (W+1, false));
    is_pino.resize(H+1, vector<bool> (W+1, false));
    
    max_lado.resize(H+1, vector<int> (W+1, 0));
    max_frutales.resize(H+1, vector<int> (W+1, 0));


    int x, y;
    for (int i = 0; i < num_pinos; i++) {
        cin >> x >> y;
        is_pino[y][x] = true;
    }
    for (int i = 0; i < num_frutales; i++) {
        cin >> x >> y;
        is_frutal[y][x] = true;
    }

    vector<pair<int, int>> best_options;
    int pino_extra, frutal_extra, lado;
    int mejor_lado = 0; int mejor_frutales = INT_MIN; 
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            max_lado[i][j] = min(max_lado[i-1][j], min(max_lado[i][j-1], max_lado[i-1][j-1])) + 1;
            pino_extra = 0; frutal_extra = 0;
            if (is_frutal[i][j]) {
                frutal_extra = 1;
            }
            if (is_pino[i][j]) {
                pino_extra = 1;
                max_lado[i][j] = 0;
            }

            tablita_frutales[i][j] = tablita_frutales[i-1][j] + tablita_frutales[i][j-1] - tablita_frutales[i-1][j-1] + frutal_extra;
            tablita_pinos[i][j] = tablita_pinos[i-1][j] + tablita_pinos[i][j-1] - tablita_pinos[i-1][j-1] + pino_extra;
            
            lado = max_lado[i][j];
            if (lado != 0) {
                max_frutales[i][j] = tablita_frutales[i][j] - tablita_frutales[i][j-lado] - tablita_frutales[i-lado][j] + tablita_frutales[i-lado][j-lado];
                if (mejor_frutales < max_frutales[i][j]) {
                    best_options.clear();
                    best_options.push_back({i, j});
                    mejor_lado = lado; mejor_frutales = max_frutales[i][j];
                }
                else if (mejor_frutales == max_frutales[i][j]) {
                    if (lado < mejor_lado) {
                        best_options.clear();
                        best_options.push_back({i, j});
                        mejor_lado = lado;
                    }
                    else if (lado == mejor_lado) {
                        best_options.push_back({i, j});
                    }
                }
            }
            
        }
    }

    //mejor_lado , mejor_frutales
    int ret_x, ret_y, i, j;
    bool keep;
    ret_x = best_options[0].second-mejor_lado; ret_y = best_options[0].first-mejor_lado;
    for (auto b : best_options)
    {
        keep = true;
        while (keep)
        {
            i = b.first; j = b.second;
            lado = mejor_lado-1;
            if (tablita_frutales[i][j] - tablita_frutales[i][j-lado] - tablita_frutales[i-lado][j] + tablita_frutales[i-lado][j-lado] == mejor_frutales) {
                mejor_lado = lado;
                ret_x = j-mejor_lado; ret_y = i-mejor_lado;
            }
            else keep = false;
            //cout << b.first << " " << b.second << endl;
        }
    }
    
    cout << ret_x << " " << ret_y << endl;
    cout << mejor_lado << endl;
    cout << mejor_frutales;
    // for (auto a : is_pino)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : is_frutal)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }

    // cout << endl;
    // for (auto a : tablita_frutales)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : tablita_pinos)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : max_lado)
    // {
    //     for (auto b : a) cout << b << " ";
    //     cout << endl;
    // }

    
}