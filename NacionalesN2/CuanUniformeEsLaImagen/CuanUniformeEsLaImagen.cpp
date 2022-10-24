#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("uniformar.in");
    ofstream ofs;
    ofs.open("uniformar.out");
    
    int N;
    string line;
    cin >> N;

    vector<vector<int>> paint (N, vector<int> (N, -1));
    vector<vector<bool>> visited (N, vector<bool> (N, false));

    for (int i = 0; i < N; i++) {
        cin >> line;
        for (int j = 0; j < N; j++)
        {
            paint[i][j] = (int) line[j] - 48;
        }
    }

    priority_queue<pair<int, pair<int, int>>> q;
    int i_actual, j_actual, moves, moved_i, moved_j;
    int max_moves = -1;

    q.push({0, {0, 0}});
    visited[0][0] = true;

    int n = 1;
    while (!q.empty())
    {
        cout << n << endl;
        n++;
        moves = q.top().first; tie(i_actual, j_actual) = q.top().second; q.pop();
        //cout << "Moves: " << moves << " - Y: " << i_actual << " - X: " << j_actual;
        for (auto mov : {1, -1}) 
        {
            moved_i = i_actual + mov;
            moved_j = j_actual + mov;
            if (moved_i >= 0 && moved_i < N && !visited[moved_i][j_actual]) 
            {
                visited[moved_i][j_actual] = true;
                if (paint[i_actual][j_actual] != paint[moved_i][j_actual]) q.push({moves-1, {moved_i, j_actual}});
                else q.push({moves, {moved_i, j_actual}});
            } 
            if (moved_j >= 0 && moved_j < N && !visited[i_actual][moved_j])
            {
                visited[i_actual][moved_j] = true;
                if (paint[i_actual][j_actual] != paint[i_actual][moved_j]) q.push({moves-1, {i_actual, moved_j}});
                else q.push({moves, {i_actual, moved_j}});
            } 
        }        
    }

    cout << (-moves);
}