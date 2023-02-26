#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;


int main()
{
    ifstream cin("carrera.in");
    ofstream cout("carrera.out");
    
    int corredores_num, m_num, h_num, terminan_num;
    cin >> corredores_num >> m_num >> h_num >> terminan_num;
    
    int a, b;
    vector<int> categoriasXedad_mujeres (81, -1);
    for (int i = 1; i <= m_num; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++) categoriasXedad_mujeres[j] = i;
    }

    vector<int> categoriasXedad_hombres (81, -1);
    for (int i = 1; i <= h_num; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++) categoriasXedad_hombres[j] = i;
    }

    vector<pair<int, char>> corredores (corredores_num+1);
    int edad;
    char sexo;
    for (int i = 1; i <= corredores_num; i++)
    {
        cin >> edad >> sexo;
        corredores[i] = {edad, sexo};
    }

    vector<vector<int>> ganadores(h_num+m_num+1, vector<int> (3, 0));
    vector<int> num_ganadores(h_num+m_num+1, 0);
    int t, categoria;
    for (int i = 0; i < terminan_num; i++)
    {
        cin >> t;
        edad = corredores[t].f; sexo = corredores[t].s;

        if (sexo == 'F') categoria = categoriasXedad_mujeres[edad];
        else categoria = categoriasXedad_hombres[edad] + m_num;

        if (num_ganadores[categoria] > 2) continue;

        ganadores[categoria][num_ganadores[categoria]] = t;
        num_ganadores[categoria]++;
    }

    for (int c = 1; c < ganadores.size(); c++)
    {
        if (c <= m_num) cout << c << " ";
        else cout << c-m_num  << " ";
        for (auto g : ganadores[c])
        {
            cout << g << " ";
        }
        cout << endl;
    }


    // for (auto a : categoriasXedad_mujeres) cout << a << " ";
    // cout << endl;
    // for (auto a : categoriasXedad_hombres) cout << a << " ";
    // cout << endl;
    // for (auto c : corredores)
    // {
    //     cout << c.f << " " << c.s << endl;
    // }
    
}
