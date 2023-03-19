#include <bits/stdc++.h>

using namespace std;

int H, L, num_conexiones;

vector<int> conexiones;

int main ()
{
    ifstream cin("casas.in");
    cin >> H >> L;
    cin >> num_conexiones;
    conexiones.resize(num_conexiones);
    for (int i = 0; i < num_conexiones; i++)
    {
        cin >> conexiones[i];
    }

    


}