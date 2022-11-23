#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> paint; 
vector<vector<bool>> visited;

void dfs(int i, int j)
{

}

int main()
{
    ifstream ifs("repintar.in");
    ofstream ofs("repintar.out");

    int N;
    ifs >> N;

    paint.resize(N+2, vector<char> (N+2, 'O'));
    visited.resize(N+2, vector<bool> (N+2, false));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) ifs >> paint[i][j];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) 
        {
            if (!visited[i][j]) dfs(i, j);
        }
    }



    for (auto a : paint)
    {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }
}