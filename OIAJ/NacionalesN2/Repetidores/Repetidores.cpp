#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs("repetidores.in");
    ofstream ofs("repetidores.out");
    
    int N;
    vector<int> num_class (3, 0);
    ifs >> N;
    map<char, int> class_num  = {{'A', 0}, {'B', 1}, {'C', 2}};
    vector<vector<int>> adj (N+1);
    vector<int> node_class (N+1);
    vector<int> has_father (N+1, false);

    int nodo_actual, num_sons, son;
    char clase_actual;
    for (int i = 0; i < N; i++)
    {
        ifs >> nodo_actual >> clase_actual >> num_sons;
        num_class[class_num[clase_actual]]++;
        node_class[nodo_actual] = class_num[clase_actual];
        for (int s = 0; s < num_sons; s++)
        {
            ifs >> son;
            adj[nodo_actual].push_back(son);
            has_father[son] = true;
        }
    }

    int root;
    for (int i = 1; i <= N; i++)
    {
        if (!has_father[i]) 
        {
            root = i;
            break;
        }
    }

    int floor;
    int num_floors = 0;
    vector<vector<int>> num_class_floor (N+1, vector<int> (3, 0));
    queue<pair<int, int>> q; q.push({root, 0});
    
    while (!q.empty())
    {
        tie(nodo_actual, floor) = q.front(); q.pop();
        num_floors = max(num_floors, floor);
        num_class_floor[floor][node_class[nodo_actual]]++;
        for (auto v : adj[nodo_actual]) q.push({v, floor+1});
    }
    num_floors++;

    int A_par = 0; int A_impar = 0;
    int B_par = 0; int B_impar = 0;
    int C_par = 0; int C_impar = 0;

    vector<vector<int>> cant (2, vector<int> (3, 0));

    for (int f = 0; f < num_floors; f++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (f % 2 == 0) cant[0][c] += num_class_floor[f][c];
            else cant[1][c] += num_class_floor[f][c];
        }
    }

    int no_A = num_class[0] + min(cant[0][1] + cant[1][2], cant[1][1] + cant[0][2]);
    int no_B = num_class[1] + min(cant[0][0] + cant[1][2], cant[1][0] + cant[0][2]);
    int no_C = num_class[2] + min(cant[0][0] + cant[1][1], cant[1][0] + cant[0][1]);

    if (no_A <= no_B &&  no_A <= no_C) ofs << no_A << " B" << " C" << endl;
    else if (no_B <= no_A &&  no_B <= no_C) ofs << no_B << " A" << " C" << endl;
    else ofs << no_C << " A" << " B" << endl;

    // cout << no_A << " " << no_B << " " << no_C << endl;

    // for (auto p : cant)
    // {
    //     for (auto a : p) cout << a << " ";
    //     cout << endl;
    // }

    // cout << A_par << " " << A_impar << " " << B_par << " " << B_impar << " " << C_par << " " << C_impar;

    // for (auto f : num_class_floor)
    // {
    //     for (auto c : f) cout << c <<  " ";
    //     cout << endl;
    // }
    // cout << num_floors << endl;

    // for (auto a : num_class) cout << a << " ";

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << " father=" << has_father[i] << endl;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << " class=" << node_class[i] << endl;
    // }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << " - ";
    //     for (auto v : adj[i]) cout << v << " , ";
    //     cout << endl;
    // }
}