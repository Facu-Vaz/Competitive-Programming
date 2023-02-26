#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream ifs("tesoro.in");
    ofstream ofs("tesoro.out");
    int num_filas, num_columnas, num_flechas;
    ifs >> num_filas >> num_columnas >> num_flechas;
    vector<vector<vector<bool>>> visited (num_flechas+1, vector<vector<bool>> (num_filas, vector<bool> (num_columnas, false)));
    vector<vector<vector<pair<int, pair<int, int>>>>> father (num_flechas+1, vector<vector<pair<int, pair<int, int>>>> (num_filas, vector<pair<int, pair<int, int>>> (num_columnas, {-1, {-1, -1}})));
    vector<vector<bool>> es_pozo (num_filas, vector<bool> (num_columnas, false));
    vector<vector<bool>> es_mostruo (num_filas, vector<bool> (num_columnas, false));

    char temp; int i_tesoro, j_tesoro;

    for (int i = 0; i < num_filas; i++)
    {
        for (int j = 0; j < num_columnas; j++)
        {
            ifs >> temp;
            if (temp == 'P') es_pozo[i][j] = true;
            else if (temp == 'W') es_mostruo[i][j] = true;
            else if (temp == 'T') {
                i_tesoro = i; j_tesoro = j;
            }
        }
    }
    visited[0][0][0] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0,0}}); 
    vector<int> moves{1, -1};
    
    bool done = false; pair<int, int> cords; int level, i, j, next_level, final_level;

    if (es_pozo[0][0]) done = false;
    if (es_mostruo[0][0]) 
    {
        num_flechas--;
        if (num_flechas < 0) done = false;
    }
    while (!q.empty() && !done) {
        tie(level, cords) = q.front(); q.pop();
        tie(i, j) = cords;
        //cout << level << " - " << i << " " << j;

        for (auto m : moves) {
            if (i + m > 0 && i + m < num_filas)
            {
                 //cout << " X";
                 if (visited[level][i+m][j]) ;
                 else if (es_mostruo[i+m][j] && level == num_flechas) visited[level][i][j+m] = true;
                 else if (!es_pozo[i+m][j]) {
                    next_level = level;
                    if (es_mostruo[i+m][j] && level != num_flechas) 
                    {   
                        for (int l = level+1; l < num_flechas+1; l++) visited[l][i+m][j] = true;
                        next_level++;
                    }
                    visited[level][i+m][j] = true;
                    father[next_level][i+m][j] = {level, {i, j}};
                    if (i+m == i_tesoro && j == j_tesoro) {
                        done = true;
                        final_level = next_level;
                    }
                    q.push({next_level, {i+m, j}});
                    //cout << "  /  " << next_level << " - " << i+m << " " << j;
                }
            }
            //cout << "E " << j+m << " E";
            if (j + m > 0 && j + m < num_columnas)
            {
                if (visited[level][i][j+m]) ;
                else if (es_mostruo[i][j+m] && level == num_flechas) visited[level][i][j+m] = true;
                else if (!es_pozo[i][j+m]) {
                    next_level = level;
                    if (es_mostruo[i][j+m] && level != num_flechas) 
                    {   
                        for (int l = level; l < num_flechas+1; l++) visited[l][i][j+m] = true;
                        next_level++;
                    }
                    visited[level][i][j+m] = true;
                    father[next_level][i][j+m] = {level, {i, j}};
                    if (i == i_tesoro && j+m == j_tesoro)  {
                        done = true;
                        final_level = next_level;
                    }
                    q.push({next_level, {i, j+m}});
                    //cout << "  /  " << next_level << " - " << i << " " << j+m;
                }
            }
        }
        //cout << endl;
    }
    //cout << endl;
    if (!done) ofs << "imposible";
    else {
        vector<pair<int, int>> path;
        i = i_tesoro; j = j_tesoro;
        while (i != 0 || j != 0) {
            path.push_back({i, j}); 
            tie(final_level, cords) = father[final_level][i][j];
            tie(i, j) = cords;
        }   
        path.push_back({0, 0}); reverse(path.begin(), path.end());

        ofs << path.size() << endl;
        for (auto n : path)
        {
            ofs << "(" << n.first << ", " << n.second << ")" << endl;
        } 
    }


}