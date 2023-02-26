#include <bits/stdc++.h>

using namespace std;

ifstream ifs("negocios.in");
ofstream ofs("negocios.out");

int main()
{
    int num_negocios, x, y, h, m, id, x2, y2, h2, m2, id2;
    ifs >> num_negocios;
    vector<tuple<int, tuple<int, int, int>, int>> vendedores (num_negocios+1, make_tuple(0, make_tuple(0, 0, 0), 0));
    for (int i = 0; i < num_negocios; i++)
    {
        ifs >> x >> y >> h >> m;
        vendedores[i+1] = make_tuple(h, make_tuple(x, y, m), i+1);
    }
    sort(vendedores.begin(), vendedores.end());
    vector<int> previous (num_negocios+1, -1);
    vector<int> max_ganacia (num_negocios+1, -1);

    tuple<int, int, int> temp;

    for (int i = 1; i <= num_negocios; i++)
    {
        tie(h, temp, id) = vendedores[i];
        tie(x, y, m) = temp;
        if (abs(x) + abs(y) <= h) max_ganacia[i] = m;
    }

    int max_index = 1;

    for (int i = 2; i <= num_negocios; i++)
    {
        if (max_ganacia[i] == -1) continue;
        tie(h, temp, id) = vendedores[i];
        tie(x, y, m) = temp;
        for (int k = 1; k < i; k++)
        {
            if (max_ganacia[k] == -1) continue; 
            tie(h2, temp, id2) = vendedores[k];
            tie(x2, y2, m2) = temp;
            if (abs(x - x2) + abs(y - y2) + h2 + 3 <= h) 
            {
                if (max_ganacia[k] + m > max_ganacia[i])
                {
                    max_ganacia[i] = max_ganacia[k] + m;
                    previous[i] = k;
                }
            }
        }  
        if (max_ganacia[i] > max_ganacia[max_index]) max_index = i;      
    }
    if (max_ganacia[max_index] == -1) ofs << 0;
    else 
    {
        ofs << max_ganacia[max_index] << endl;
        vector<int> trace; 
        while (max_index != -1)
        {
            tie(h, temp, id) = vendedores[max_index];
            tie(x, y, m) = temp;
            trace.push_back(id);
            max_index = previous[max_index];
        }
        for (int i = trace.size()-1; i >= 0; i--)
        {
            ofs << trace[i] << " ";
        }
    }


    // for (auto a: vendedores)
    // {
        
    //     tie(h, temp) = a;
    //     tie(x, y, m) = temp;
    //     cout << x << " " << y << " " << h << " " << m << endl;
    // }
    // cout << endl;
    // for (auto a : max_ganacia)
    // {
    //     cout << a << endl;
    // }
}
