#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<bool>>> pintura;
map<char, int> col_num = {{'R', 0}, {'Z', 1}, {'A', 2}};

int N, P, Q;

void pintar(char o, int n, char col, int a, int b) {
    if (o == 'F') {
        for (int i = a; i <= b; i++) {
            pintura[i][n][col_num[col]] = true;
        }
    }
    else {
        for (int i = a; i <= b; i++) {
            pintura[n][i][col_num[col]] = true;
        }
    }
}

bool evaluar(char o, int n, char col, int a, int b) {
    if (o == 'F') {
        for (int i = a; i <= b; i++) {
            if (!pintura[i][n][col_num[col]]) {
                return false;
            }
        }
    }
    else {
        for (int i = a; i <= b; i++) {
            if (!pintura[n][i][col_num[col]]) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ifstream cin("copia.in");
    ofstream cout("copia.out");
    
    cin >> N;
    pintura.resize(N+1, vector<vector<bool>> (N+1, vector<bool> (3, false)));
    cin >> P;

    int a, b, n;
    char col, o;
    for (int i = 0; i < P; i++) {
        cin >> o >> n >> col >> a >> b;
        pintar(o, n, col, a, b);
    }

    cin >> Q;
    bool ok = true;
    int ret = 0;
    for (int i = 0; i < Q; i++) {
        cin >> o >> n >> col >> a >> b;
        ok = evaluar(o, n, col, a, b);
        if (ok) ret++;
    }

    cout << ret;
}