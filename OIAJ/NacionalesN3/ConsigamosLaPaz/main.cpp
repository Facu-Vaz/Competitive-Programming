#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<bool>> is_isla;
vector<vector<bool>> processed;
vector<vector<int>> num_isla;

vector<bool> visited;
vector<bool> visited2;


vector<int> per_row;
vector<int> per_col;

int cant_islas = 0;

void dfs(int i, int j) {
    num_isla[i][j] = cant_islas + 1;
    processed[i][j] = true;
    if (i - 1 >= 0) {
        if (is_isla[i-1][j] && !processed[i-1][j]) dfs(i-1, j);
    }
    if (i + 1 < N) {
        if (is_isla[i+1][j] && !processed[i+1][j]) dfs(i+1, j);
    }
    if (j - 1 >= 0) {
        if (is_isla[i][j-1] && !processed[i][j-1]) dfs(i, j-1);
    }
    if (j + 1 < N) {
        if (is_isla[i][j+1] && !processed[i][j+1]) dfs(i, j+1);
    }
}

int main() {

    ifstream cin("litigo.in");
    cin >> N;
    char p;

    is_isla.resize(N, vector<bool> (N, false));
    processed.resize(N, vector<bool> (N, false));
    num_isla.resize(N, vector<int> (N, 0));

    per_row.resize(N);
    per_col.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> p; 
            is_isla[i][j] = (p == '1');
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (processed[i][j]) continue;
            processed[i][j] = true;
            if (is_isla[i][j]) {
                dfs(i, j);
                cant_islas++;
            }
        }
    }  

    int temp = 0;

    visited.resize(N+1, false);
    for (int i = N-1; i >= 0; i--) {
        temp = 0;
        for (int j = 0; j < N; j++) {
            if (num_isla[i][j] != 0 && !visited[num_isla[i][j]]) {
                temp++;
                visited[num_isla[i][j]] = true;
            }
        }
        per_row[i] = temp;
        if (i < N-1) per_row[i] += per_row[i+1];
    }

    visited2.resize(N+1, false);
    for (int j = 0; j < N; j++) {
        temp = 0;
        for (int i = N-1; i >= 0; i-- ) {
            if (num_isla[i][j] != 0 && !visited2[num_isla[i][j]]) {
                temp++;
                visited2[num_isla[i][j]] = true;
            }
        }
        per_col[j] = temp;
        if (j > 0) per_col[j] += per_col[j-1];
    }

    cout << "  ";
     for (auto a : per_col) cout << a << " ";
    cout << endl;

     for (auto a : per_row) cout << a << endl;
    
    vector<char> moves = {'N'};

    w



    cout << endl << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << num_isla[i][j];
        }
        cout << endl;
    }
}