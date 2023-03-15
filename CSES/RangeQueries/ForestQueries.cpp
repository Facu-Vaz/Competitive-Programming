#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tablitas;
int N, num_queries, extra;

int main ()
{
    cin >> N >> num_queries;
    char temp;
    tablitas.resize(N+1, vector<int> (N+1, 0));
    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            cin >> temp;
            extra = (temp == '*') ? 1 : 0;
            tablitas[i][j] = tablitas[i-1][j] + tablitas[i][j-1] - tablitas[i-1][j-1] + extra;
        }
    }
    int y1, x1, y2, x2;
    vector<int> ret;
    for (int q = 0; q < num_queries; q++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        ret.push_back(tablitas[y2][x2] - tablitas[y2][x1-1] - tablitas[y1-1][x2] + tablitas[y1-1][x1-1]);
    }

    for (auto r : ret) cout << r << endl;
}