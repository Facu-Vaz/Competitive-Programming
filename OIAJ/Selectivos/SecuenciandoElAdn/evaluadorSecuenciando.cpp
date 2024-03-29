// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
#include "secuenciando.cpp"

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

string secuenciar(int N, string s);

string secret;
int preguntas = 0;

int medir(string cad)
{
    preguntas++;
    int i=0;
    for (int j=0;j<int(secret.size()); j++)
    if (i < int(cad.size()) && cad[i] == secret[j])
        i++;
    return i == int(cad.size());
}

int main()
{
    ifstream cin("secuenciando.in");
    
    string s;
    getline(cin, s);
    getline(cin, secret);
    string resultado = secuenciar(int(secret.size()), s);
    
    if (resultado != secret)
    {
        cout << "Resultado erroneo: " << resultado << endl;
        cout << preguntas << " preguntas realizadas." << endl;
    }
    else
    {
        cout << "Se adivino con exito!!" << endl;
        cout << preguntas << " preguntas realizadas." << endl;
    }
    return 0;
}
