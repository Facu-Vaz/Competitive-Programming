// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.
#include "BuscandoLaMejorGanancia.cpp"

#include <iostream>
#include <vector>

using namespace std;

// Para compilar en Geany, no se utiliza el siguiente fragmento con el struct. Compilando de otras maneras, podria ser necesario tenerlo.
/*
// *********** IMPORTANTE!!!!!! ********************
// NO MODIFICAR DE NINGUNA MANERA ESTE STRUCT!!!!!**
struct PQ{ int precio, cantidad; } ; //  ***********
// *************************************************
// *************************************************
*/


int ganancia( int P, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp );

int main()
{
    ifstream ifs;
    ifs.open("ejemplo.in");
    ofstream ofs;
    ofs.open("ejemplo.out");
    
    int P, F, C;
    ifs >> P >> F >> C;
    vector<PQ> fab, comp;
    fab.resize(F);
    for (int i=0;i<F;i++)
        ifs >> fab[i].precio >> fab[i].cantidad;
    comp.resize(C);
    for (int i=0;i<C;i++)
        ifs >> comp[i].precio >> comp[i].cantidad;
    int Fab, Comp;
    int utilidad = ganancia(P, fab, comp, Fab, Comp);
    ofs << Fab << " " << Comp << " " << utilidad << endl;
    return 0;
}
