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
        cout << x << y << endl;
        is_pino[y][x] = true;
    }
    for (int i = 0; i < num_frutales; i++) {
        cin >> x >> y;
        cout << x << y << endl;
        is_frutal[y][x] = true;
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= )
    }

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
}