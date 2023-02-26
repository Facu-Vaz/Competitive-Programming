#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Fecha
{
    int dia, mes, anno;
};

bool sortRet (pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

int fila(vector<Fecha> orden, vector<int> &enojados)
{
    vector<int> cola (1,0);
    vector<int> mas_joven (1,0);
    vector<pair<int, int>> enojos;
    for (int c = 1; c <= orden.size(); c++)
    {
        cola.push_back(orden[c-1].dia+(orden[c-1].mes*32)+(orden[c-1].anno*365));
        if (c == 1) mas_joven.push_back(cola[1]);
        else {
            mas_joven.push_back(max(mas_joven[c-1], cola[c]));
            int a = 0; int b = c; int j = (a+b)/2;
            while (b-a > 1) {
                if (mas_joven[j] > cola[c]) b = j;
                else a = j;
                j = (a+b)/2;
            }
            if (c-b > 0) enojos.push_back({c-b, c});
        }
    }

    sort(enojos.begin(), enojos.end(), sortRet);
    enojados.resize(enojos.size());

    for (int e = 0; e < enojos.size(); e++) {
        enojados[e] = enojos[e].second;
    }

    // cout << endl;

    // for (auto a : cola) cout << a << endl;

    // cout << endl;

    // for (auto a : mas_joven) cout << a << endl;

    if (enojos.size() > 0) return enojos[0].first;
    return 0;

}
