#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream ifs("latas.in");
    ofstream ofs("latas.out");
    int l;
    ifs >> l;

    vector<vector<int>> piramide (l, vector<int> (l, 0));
    int total_peso = 0;

    for (int i = 0; i < l; i++) {
        for (int k = 0; k <= i; k++) {
            ifs >> piramide[i][k];
            total_peso += piramide[i][k];
        }
    }

    vector<vector<int>> diagonal (l, vector<int> (l, 0));
    vector<vector<int>> tablita (l, vector<int> (l, 0));
    bool hay_abajo, hay_derecha;
    int min_movimiento = INT_MAX; 
    int num_diagonal, mov_k, mov_i; 
    for (int i = l-1; i >= 0; i--)
    {
        for (int k = i; k >= 0; k--)
        {
            //cout << i << " " << k;
            diagonal[i][k] = piramide[i][k];
            hay_abajo = i != l-1 && k != 0;
            hay_derecha = i != k;   
            if (i != l-1 && k != 0) diagonal[i][k] += diagonal[i+1][k-1];
            if (i != k) diagonal[i][k] += diagonal[i][k+1];
            if ((i != l-1 && k != 0) && (i != k)) diagonal[i][k] -= diagonal[i+1][k];
            //cout << " A ";
            tablita[i][k] = piramide[i][k];
            if (i != l-1) tablita[i][k] += tablita[i+1][k];
            if (i != k) tablita[i][k] += tablita[i][k+1];
            if (i != l-1 && i != k) tablita[i][k] -= tablita[i+1][k+1];
            //cout << " B ";
            if (i + k >= l-1) min_movimiento = min(min_movimiento, total_peso - tablita[i][k]);
            else 
            {
                num_diagonal = l - (i + k) - 2;
                if (num_diagonal % 2 == 0) {
                    mov_k = num_diagonal / 2;
                    mov_i = num_diagonal / 2;
                }
                else {
                    mov_k = num_diagonal / 2 + 1;
                    mov_i = num_diagonal / 2;
                }
                min_movimiento = min(min_movimiento, total_peso - tablita[i][k] + diagonal[l-1-mov_i][l-1-mov_k]);
            }
            //cout << "DONE" << endl;
        }
    }

    // for (auto a : piramide)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : diagonal)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (auto a : tablita)
    // {
    //     for (auto b : a)
    //     {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    ofs << min_movimiento;
}