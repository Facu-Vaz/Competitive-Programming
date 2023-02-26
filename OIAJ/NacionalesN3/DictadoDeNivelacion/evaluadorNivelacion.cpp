// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.
#include "DictadoDeNivelacion.cpp"

#include <iostream>
#include <string>

using namespace std;

int nivelacion( string palabra );

int main()
{
    ifstream ifs;
    ifs.open("ejemplo.in");
    
    string s; ifs >> s;
    cout << nivelacion(s) << endl;
    return 0;
}
