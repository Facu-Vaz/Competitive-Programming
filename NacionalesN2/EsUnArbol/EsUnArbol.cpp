#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited(0,0);
int cont = 0;

void DFS(int a)
{
    cont++;
    visited[a] = true;
    for (int i : adj[a]) if (!visited[i]) DFS(i);
}

int main()
{
    ifstream cin("arbol.in");
    ofstream cout("arbol.out");
    
    int nodos_num, conexiones_num;
    cin >> nodos_num >> conexiones_num;
    adj.resize(nodos_num+1);
    visited.resize(nodos_num+1, false);
    vector <int> padres_num(nodos_num+1,0);

    for (int i = 0; i < conexiones_num; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        padres_num[b]++;
    }

    vector<int> regla1;
    vector<int> regla2;

    for (int i = 1; i <= nodos_num; i++)
    {
        if (padres_num[i] == 0) regla1.push_back(i);
        else if (padres_num[i] > 1) regla2.push_back(i);
    }

    if (regla1.size()==1) DFS(regla1[0]);


    if (cont == nodos_num && regla1.size() == 1 && regla2.size()==0) cout << "Si " << regla1[0] << endl;
    else 
    {
        cout << "No" << endl;
        if (regla1.size()==0) cout << 0;
        else for (int i:regla1) cout << i << " ";
        cout << endl;
        if (regla2.size()==0) cout << 0;
        else for (int i:regla2) cout << i << " ";
        cout << endl;
        if (cont == nodos_num || regla1.size() != 1) cout << 0;
        else for (int i = 1; i <= nodos_num; i++) if (!visited[i]) cout << i << " ";
        cout << endl;
    }


}