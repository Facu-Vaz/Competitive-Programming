#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs("polimorfo.in");
    ofstream ofs("polimorfo.out");
    cout << "AAA";
    int N, largo_ciclo;
    ifs >> N >> largo_ciclo;

    if (largo_ciclo > N){
        ofs << 0;
        return 0;
    }

    vector<int> esta_en_ciclo (largo_ciclo+1, 0);
    int num_en_ciclo = 0;
    vector<int> ret;
    vector<int> lista;
    int trozo;

    for (int n = 0; n < largo_ciclo; n++)
    {
        ifs >> trozo;
        cout << trozo;
        lista.push_back(trozo);
        if (trozo < 1 || trozo > largo_ciclo) continue;
        if (!esta_en_ciclo[trozo]) {
            esta_en_ciclo[trozo]++;
            num_en_ciclo++;
        }
        else {
            esta_en_ciclo[trozo]++;
        }
    }

    if (num_en_ciclo == largo_ciclo) ret.push_back(1);
    int fin = N - largo_ciclo;

    for (int n = 1; n <= fin; n++)
    {
        ifs >> trozo;
        cout << trozo;
        lista.push_back(trozo);

        if (lista[n-1] > 0 && lista[n-1] <= largo_ciclo)
        {
            if (esta_en_ciclo[lista[n-1]])
            {
                esta_en_ciclo[lista[n-1]]--;
                if (!esta_en_ciclo[lista[n-1]]) num_en_ciclo--;
            }
        }

        if (trozo < 1 || trozo > largo_ciclo) continue;

        esta_en_ciclo[trozo]++;
        if (esta_en_ciclo[trozo] == 1)
        {
            num_en_ciclo++;
        }

        if (num_en_ciclo == largo_ciclo) ret.push_back(n+1);
    }

    ofs << ret.size() << endl;
    if (ret.size() <= 10)
    {
        for (auto r : ret) 
        {
            ofs << r << " ";
        }
    }
    else 
    {
        for (int i = 0; i < 5; i++) ofs << ret[i] << " ";
        for (int i = ret.size()-5; i < ret.size(); i++) ofs << ret[i] << " ";
    }
}
