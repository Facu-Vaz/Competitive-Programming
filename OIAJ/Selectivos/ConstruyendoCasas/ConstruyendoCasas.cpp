#include <bits/stdc++.h>

using namespace std;

int H, L, num_conexiones;

vector<int> conexiones;
vector<int> maximo_radio;
vector<vector<int>> dp_radio;
vector<vector<int>> dp_area;

int main ()
{
    ifstream cin("casas.in");
    cin >> H >> L;
    cin >> num_conexiones;
    conexiones.resize(num_conexiones+2);
    maximo_radio.resize(num_conexiones+2);

    dp_radio.resize(H/2 + 1, vector<int> (num_conexiones+2, 0));
    dp_area.resize(H/2 + 1, vector<int> (num_conexiones+2, 0));

    for (int i = 1; i <= num_conexiones; i++) dp_radio[1][i] = 1;
    for (int i = 1; i <= num_conexiones; i++) dp_area[1][i] = 4;


    conexiones[0] = 0; conexiones[num_conexiones+1] = L;
    for (int i = 1; i <= num_conexiones; i++) cin >> conexiones[i];
    
    maximo_radio[1] = min(H/2, min(conexiones[1]-conexiones[0], conexiones[2]-conexiones[1]-1));
    maximo_radio[num_conexiones] = min(H/2, min(conexiones[num_conexiones]-conexiones[num_conexiones-1]-1, conexiones[num_conexiones+1]-conexiones[num_conexiones]));
    for (int i = 2; i < num_conexiones; i++) 
    {
        maximo_radio[i] = min(H/2, min(conexiones[i]-conexiones[i-1]-1, conexiones[i+1]-conexiones[i]-1));
    }


    for (auto c : conexiones) cout << c << " ";    
    cout << endl << endl;
    for (auto c : maximo_radio) cout << c << " ";    
    cout << endl << endl;
    for (auto a : dp_area) {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }
    cout << endl;
    for (auto a : dp_radio) {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }


}