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
    vector<int> proveedor_x_unidad (100001, -1);

    sort(fab.begin(), fab.end(), sortFabs);

    int prov = fab[0].first; 
    int pointer = 1; 
    int x_unidad = fab[0].second.precio;
    int min_unidades = fab[0].second.cantidad;
    int pago, posible_pago;
    bool skip = fab.size() == 1;

    for (int c = min_precio_unidad.size()-1; c >= 0; c--)
    {
        //cout << fab[pointer].second.cantidad << " ";
        if (c < min_unidades) pago = x_unidad * min_unidades;
        else pago = x_unidad * c;

        if (skip)
        {
            min_precio_unidad[c] = pago;
            proveedor_x_unidad[c] = prov; 
        }

        if (c < fab[pointer].second.cantidad) posible_pago = fab[pointer].second.cantidad * fab[pointer].second.precio;
        else posible_pago = fab[pointer].second.precio * c;
        if (posible_pago < pago)
        {
            //cout << prov << " ";
            //cout << "cambio";
            prov = fab[pointer].first; 
            //cout << prov << endl;
            x_unidad = fab[pointer].second.precio;
            min_unidades = fab[pointer].second.cantidad;
            if (pointer+1 < fab.size()) pointer++;

            min_precio_unidad[c] = posible_pago;
        }
        else 
        {
            min_precio_unidad[c] = pago;
            if (c < fab[pointer].second.cantidad){
                if (pointer+1 < fab.size()) pointer++;
            }
        }

        proveedor_x_unidad[c] = prov; 
    }

    int best_ganancia = INT_MIN;
    int best_proveedor, best_comprador, ganancia_actual;
    for (int c = 0; c < compradores.size(); c++)
    {
        if (min_precio_unidad[compradores[c].cantidad] > P)
        {
            continue;
        }
        ganancia_actual = (compradores[c].precio * compradores[c].cantidad) - min_precio_unidad[compradores[c].cantidad];
        if (ganancia_actual > best_ganancia)
        {
            best_ganancia = ganancia_actual;
            Fab = proveedor_x_unidad[compradores[c].cantidad] + 1;
            Comp = c+1;
        }
        //cout << ganancia_actual << endl;
    }

    if (best_ganancia < 0) return -1;

    return best_ganancia;

    // for (int c = 0; c < compradores.size(); c++)
    // {
    //     cout << min_precio_unidad[compradores[c].cantidad] << endl;
    // }

    // for (auto c : proveedor_x_unidad)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    // for (auto c : min_precio_unidad)    
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    // for (auto f : fab) {
    //     cout << f.first << " " << f.second.precio << " " << f.second.cantidad << endl;
    // }

    // for (auto c : compradores) {
    //     cout << c.precio << " " << c.cantidad << endl;
    // }

    return 0;
}
