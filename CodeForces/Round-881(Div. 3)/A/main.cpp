#include <bits/stdc++.h>

using namespace std;

int solve() 
{
    int lista_size;
    cin >> lista_size;
    if (lista_size == 1) return 0;
    vector<int> lista(lista_size);
    for (int i = 0; i < lista_size; i++) cin >> lista[i];

    sort(lista.begin(), lista.end());

    int suma = 0;
    for (int i = 0; i < lista_size / 2; i++) {
        // cout << lista[i] << " " << lista[lista_size-1] << endl;
        suma += lista[lista_size-i-1]; suma -= lista[i];
    }

    return suma;
}

int main() 
{
    int num_times;
    cin >> num_times;
    vector<int> ret;
    for (int i = 0; i < num_times; i++) ret.push_back(solve());

    for (auto r : ret) cout << r << endl;
}