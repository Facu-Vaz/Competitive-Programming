#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("maxinum.in");
    ofstream ofs;
    ofs.open("maxinum.out");
    
    int n, temp;
    ifs >> n;
    vector<int> pares; pares.push_back(0);
    vector<int> impares; impares.push_back(0);
    vector<int> max_lista_pares; max_lista_pares.push_back(0);
    vector<int> max_lista_impares; max_lista_impares.push_back(0); 
    vector<int> sobra_lista_pares; sobra_lista_pares.push_back(0);
    vector<int> sobra_lista_impares; sobra_lista_impares.push_back(0); 
    for (int i = 0; i < n; i++)
    {
        ifs >> temp; 
        if (i % 2 == 0){ 
            pares.push_back(temp);
            max_lista_pares.push_back(0);
            sobra_lista_pares.push_back(0);
        }
        else {
            impares.push_back(temp);
            max_lista_impares.push_back(0);
            sobra_lista_impares.push_back(0);
        }
    }
    sobra_lista_pares[1] = pares[1];
    sobra_lista_impares[1] = impares[1];

    for (int i = 2; i < pares.size(); i++)
    {
        if (max_lista_pares[i-1] > max_lista_pares[i-2]+(pares[i] * pares[i-1]))
        {
            max_lista_pares[i] = max_lista_pares[i-1];
            sobra_lista_pares[i] = sobra_lista_pares[i-1] + pares[i];
        }
        else
        {
            max_lista_pares[i] = max_lista_pares[i-2]+(pares[i] * pares[i-1]);
            sobra_lista_pares[i] = sobra_lista_pares[i-2];
        }
    }

    for (int i = 2; i < impares.size(); i++)
    {
        if (max_lista_impares[i-1] > max_lista_impares[i-2]+(impares[i] * impares[i-1]))
        {
            max_lista_impares[i] = max_lista_impares[i-1];
            sobra_lista_impares[i] = sobra_lista_impares[i-1] + impares[i];
        }
        else
        {
            max_lista_impares[i] = max_lista_impares[i-2]+(impares[i] * impares[i-1]);
            sobra_lista_impares[i] = sobra_lista_impares[i-2];
        }
    }

    int ret =  max_lista_pares[max_lista_pares.size()-1] + max_lista_impares[max_lista_impares.size()-1];
    int sobra = sobra_lista_pares[sobra_lista_pares.size()-1] + sobra_lista_impares[sobra_lista_impares.size()-1];
    ofs << ret << endl;
    ofs << sobra;
}