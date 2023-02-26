#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y)
{
    if (x.first.first != y.first.first)
        return x.first.first > y.first.first; //return the one with smaller first element
    else
        return x.first.second < y.first.second; //if first element is equal then return the one with smaller second element
}   
 
int n = 128;
vector<int> segTree (n*2, 0);

int sum (int a, int b)
{
    a += n; b += n;
    int s = 0;
    while (a <= b) {
        if (a%2 == 1) s += segTree[a++];
        if (b%2 == 0) s += segTree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void add (int k)
{
    k += n;
    segTree[k] += 1;
    for (k /= 2; k >= 1; k /= 2) {
        segTree[k] = segTree[k*2]+segTree[k*2+1];
    }
}

int main()
{
    ifstream ifs("clima.in");
    ofstream ofs("clima.out");
    int num_estaciones, num_mediciones, maxima, minima, temp_max, temp_min;
    ifs >> num_estaciones;
    vector<pair<pair<int, int>, int>> estaciones;
    vector<int> hostilidad_por_estacion (num_estaciones+1, 0);
    vector<int> veces_repetido (num_estaciones+1, 0);
    for (int e = 0; e < num_estaciones; e++)
    {
        maxima = INT_MIN;
        minima = INT_MAX;
        ifs >> num_mediciones;
        for (int m = 0; m < num_mediciones; m++)
        {
            ifs >> temp_min >> temp_max;
            maxima = max(maxima, temp_max);
            minima = min(minima, temp_min);
        }
        estaciones.push_back({{minima+51, maxima+51}, e+1});
    }

    sort(estaciones.begin(), estaciones.end(), cmp);

    pair<int, int> temperaturas; int id, hositlidad_actual;
    int max_previo = INT_MAX;
    int min_previo = INT_MIN;
    vector<int> tanda_repetidos;
    for (auto e : estaciones)
    {
        tie(temperaturas, id) = e;
        tie(minima, maxima) = temperaturas;
        hositlidad_actual = sum(minima, maxima);
        add(maxima);
        if (minima == min_previo && maxima == max_previo) 
        {
            tanda_repetidos.push_back(id);
        }
        else {
            if (tanda_repetidos.size() > 1)
            {
                for (auto r : tanda_repetidos)
                {
                    veces_repetido[r] += tanda_repetidos.size();
                }
            }
            tanda_repetidos.clear();
            tanda_repetidos.push_back(id);
        }

        hostilidad_por_estacion[id] += hositlidad_actual - (tanda_repetidos.size() - 1);
        max_previo = maxima; min_previo = minima;
    }
    for (auto r : tanda_repetidos)
    {
        veces_repetido[r] += tanda_repetidos.size() - 1;
    } 
    vector<int> ret;
    int max_hostilidad = -1;

    for (int i = 1; i < hostilidad_por_estacion.size(); i++)
    {
        if (hostilidad_por_estacion[i] > max_hostilidad)
        {
            ret.clear();
            max_hostilidad = hostilidad_por_estacion[i];
            ret.push_back(i);
        }
        else if (hostilidad_por_estacion[i] == max_hostilidad) ret.push_back(i);   
    }

    for (auto a : ret)
    {
        ofs << a << " " << (num_estaciones - 1 - hostilidad_por_estacion[a] - veces_repetido[a]) << endl;
    }

    // for (auto e : estaciones)
    // {
    //     cout << e.second << " - " << e.first.first << " " << e.first.second << endl;
    // }
    // cout << endl;
    // for (int i = 1; i < hostilidad_por_estacion.size(); i++)
    // {
    //     cout << i << " - " << hostilidad_por_estacion[i] << endl;
    // }
    // cout << endl;
    // for (int i = 1; i < veces_repetido.size(); i++)
    // {
    //     cout << i << " - " << veces_repetido[i] << endl;
    // }
    


}