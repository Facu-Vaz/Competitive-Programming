#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs("protesta.in");
    ofstream ofs("protesta.out");

    int calles_num;
    ifs >> calles_num;

    int inicio_j, inicio_i, fin_j, fin_i;
    ifs >> inicio_j >> inicio_i >> fin_j >> fin_i;

    fin_j = fin_j / 2; inicio_j = inicio_j / 2;
    fin_i = fin_i / 2 + 1; inicio_i = inicio_i / 2 + 1;

    int obstaculos_num, obstaculo_i, obstaculo_j;
    ifs >> obstaculos_num;

    int width = calles_num / 2;
    int heigth = (calles_num % 2 == 0) ? width : width+1;
    
    vector<vector<bool>> obstaculos (heigth+2, vector<bool> (width+2, false));
    vector<vector<bool>> visited (heigth+2, vector<bool> (width+2, false));
    vector<vector<pair<int, int>>> father (heigth+2, vector<pair<int, int>> (width+2, {-1, -1}));

    vector<vector<bool>> welldone (heigth+2, vector<bool> (width+2, false));

    for (int i = 0; i < width+2; i++) {
        obstaculos[0][i] = true;
        obstaculos[heigth+1][i] = true;
    }
    for (int i = 0; i < heigth+2; i++) {
        obstaculos[i][0] = true;
        obstaculos[i][width+1] = true;
    }

    for (int o = 0; o < obstaculos_num; o++)
    {
        ifs >> obstaculo_j >> obstaculo_i;
        obstaculo_i = obstaculo_i / 2 + 1; 
        obstaculo_j = obstaculo_j / 2;
        obstaculos[obstaculo_i][obstaculo_j] = true;
    }

    deque<pair<int, pair<int, int>>> dq;
    visited[inicio_i][inicio_j] = true;
    dq.push_front({-1, {inicio_i, inicio_j}});
    bool done = false;
    int actual_i, actual_j, coste_actual, direccion, move_i, move_j;

    while (!dq.empty() && !done)
    {
        direccion = dq.front().first; tie(actual_i, actual_j) = dq.front().second;
        dq.pop_front();
        //cout << actual_j << " " << actual_i << " " << direccion << endl;

        welldone[actual_i][actual_j] = true;

        // for (int i = welldone.size()-1; i >= 0; i--)
        // {
        //     for (auto b : welldone[i]) cout << b << " ";
        //     cout << endl;
        // }
       

        move_j = (actual_i % 2 == 0) ? 1 : -1;
        move_i = (actual_j % 2 == 0) ? 1 : -1;
        if (!visited[actual_i][actual_j+move_j])
        {
            if (!obstaculos[actual_i][actual_j+move_j])
            {
                visited[actual_i][actual_j+move_j] = true;
                father[actual_i][actual_j+move_j] = {actual_j, actual_i};
                if (actual_i == fin_i && actual_j+move_j == fin_j) done = true;

                if (direccion == 0 || direccion == -1) dq.push_front({0, {actual_i, actual_j+move_j}});
                else dq.push_back({0, {actual_i, actual_j+move_j}});

                //cout << actual_i << " " << actual_j+move_j << " , ";
            }
        }
        if (!visited[actual_i+move_i][actual_j])
        {
            if (!obstaculos[actual_i+move_i][actual_j])
            {
                visited[actual_i+move_i][actual_j] = true;
                father[actual_i+move_i][actual_j] = {actual_j, actual_i};
                if (actual_i+move_i == fin_i && actual_j == fin_j) done = true;

                if (direccion == 1 || direccion == -1) dq.push_front({1, {actual_i+move_i, actual_j}});
                else dq.push_back({1, {actual_i+move_i, actual_j}});

                //cout << actual_i+move_i << " " << actual_j << " , ";
            }
        }
        //cout << endl;
    }

    if (!done) cout << 0;
    else 
    {
        cout << 1 << endl;
        direccion = -1;
        actual_i = fin_i; actual_j = fin_j;
        int next_j, next_i;
        vector<int> ret;
        while (actual_i != -1 && actual_j != -1)
        {
            //cout << actual_j << " " << actual_i << endl;
            tie(next_j, next_i) = father[actual_i][actual_j];
            if (next_i == actual_i)
            {
                if (direccion == 1 || direccion == -1)
                {
                    ret.push_back(actual_i * 2 - 1);
                    direccion = 0;
                }
            }
            if (next_j == actual_j)
            {
                if (direccion == 0 || direccion == -1)
                {
                    ret.push_back(actual_j * 2);
                    direccion = 1;
                }
            }
            actual_i = next_i; actual_j = next_j;
        }

        cout << ret.size() << endl;
        reverse(ret.begin(), ret.end());
        for (auto a : ret) cout << a << endl;
    }

    // for (int i = obstaculos.size()-1; i >= 0; i--)
    // {
    //     for (auto b : obstaculos[i]) cout << b << " ";
    //     cout << endl;
    // }
}