#include <vector>
#include <bits/stdc++.h>

using namespace std;

// *********** IMPORTANTE!!!!!! ********************
// NO MODIFICAR DE NINGUNA MANERA ESTE STRUCT!!!!!**
struct PQ{ int precio, cantidad; } ; //  ***********
// *************************************************
// *************************************************

bool sortFabs(pair<int, PQ> a, pair<int, PQ> b)
{
    return a.second.precio < b.second.precio;
}

int ganancia( int P, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp )
{
    vector<pair<int, PQ>> fab;
    for (int i = 0; i < fabricantes.size(); i++)
    {
        fab.push_back(make_pair(i, fabricantes[i]));
    }

    vector<int> min_precio_unidad (100001, -1);
    vector<int> proveedor (100001, -1);

    sort(fab.begin(), fab.end(), sortFabs);

    int prov = fab[0].first; 
    int pointer = 1; 
    int x_unidad = fab[0].second.precio;
    int min_unidades = fab[0].second.cantidad;
    int pago;

    for (int c = min_precio_unidad.size()-1; c >= 0; c--)
    {
        //cout << fab[pointer].second.cantidad << " ";
        if (c < min_unidades) pago = x_unidad
        
    }

    // for (int c = 0; c < compradores.size(); c++)
    // {
    //     cout << min_precio_unidad[compradores[c].cantidad] << endl;
    // }

    // for (auto c : proveedor)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    for (auto f : fab) {
        cout << f.first << " " << f.second.precio << " " << f.second.cantidad << endl;
    }

    // for (auto c : compradores) {
    //     cout << c.precio << " " << c.cantidad << endl;
    // }

    return 0;
}
