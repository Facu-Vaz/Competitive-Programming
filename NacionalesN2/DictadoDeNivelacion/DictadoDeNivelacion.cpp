#include <string>
#include <bits/stdc++.h>

using namespace std;

int inicio, fin, min_add;
bool done;

int prueba( string palabra )
{
    if (palabra.size() == 1) return 0;
    
    int length = palabra.size();

    // A A B A A C
    for (int i = length-1; i >= 0; i--)
    {
        inicio = 0; fin = i;
        while (palabra[inicio] == palabra[fin])
        {
            if (inicio == fin || inicio+1 == fin)
            {
                min_add = length - (i + 1);
                //cout << "AA " << min_add << endl;
                done = true;
                break;
            }
            inicio++; fin--;
        }
        if (done) break;
    }

    done = false;

    for (int i = 0; i <= length-1; i++)
    {
        inicio = i; fin = length-1;
        if (i > min_add) break;
        while (palabra[inicio] == palabra[fin])
        {
            if (inicio == fin || inicio+1 == fin)
            {
                if (i < min_add)
                {
                    min_add = i;
                    //cout << "AA " << min_add << endl;
                    done = true;
                    break;
                }
            }
            inicio++; fin--;
        }
        if (done) break;
    }

    return min_add;
}
