#include <bits/stdc++.h>

using namespace std;

int H, L, num_conexiones;
vector<int> conexiones;
vector<int> maximo_radio;
vector<int> areas;
vector<vector<int>> dp_radio;
vector<vector<int>> dp_area;
vector<vector<int>> previous;

int main ()
{
    ifstream cin("casas.in");
    ofstream cout("casas.out");
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> L;
    cin >> num_conexiones;

    conexiones.resize(num_conexiones+2);
    maximo_radio.resize(num_conexiones+2);
    areas.resize(H+1, 0); for (int i = 1; i <= H; i++) areas[i] = i*i*4; 

    dp_radio.resize(H/2 + 1, vector<int> (num_conexiones+1, 0));
    dp_area.resize(H/2 + 1, vector<int> (num_conexiones+1, 0));
    previous.resize(H/2 + 1, vector<int> (num_conexiones+1, 0));

    conexiones[0] = 0; conexiones[num_conexiones+1] = L;
    for (int i = 1; i <= num_conexiones; i++) cin >> conexiones[i];

    int left, right;
    for (int i = 1; i <= num_conexiones; i++) {
        left = (i == 1) ? 0 : 1;
        right = (i == num_conexiones) ? 0 : 1;
        maximo_radio[i] = min(H/2, min(conexiones[i]-conexiones[i-1]-left, conexiones[i+1]-conexiones[i]-right));
    }

    int max_area, diff, maximo;
    bool keep;
    int final_area, final_radio, final_previous;

    for (int c = 1; c <= num_conexiones; c++) {
        for (int h = 1; h <= H/2; h++) {
            diff = conexiones[c] - conexiones[c-1] - h;
            final_area = dp_area[h-1][c];
            final_radio = dp_radio[h-1][c];
            final_previous = previous[h-1][c];
            if (h > maximo_radio[c]) {
                final_area = dp_area[h-1][c];
                final_radio = dp_radio[h-1][c];
                final_previous = previous[h-1][c];
            }
            else if (diff >= 0 && diff <= H/2 && h <= maximo_radio[c]) {
                max_area = dp_area[h-1][c];
                if (dp_area[diff][c-1] + areas[h] > max_area) {
                    max_area = dp_area[diff][c-1] + areas[h];
                    final_radio = h;
                    final_previous = diff;
                }
                final_area = max_area;
            }
            else if (diff > H/2) {
                final_area = dp_area[H/2][c-1] + areas[h];
                final_radio = h;
                final_previous = H/2;
            }
            dp_area[h][c] = final_area;
            dp_radio[h][c] = final_radio;
            previous[h][c] = final_previous;
        }
    }        

    cout << dp_area[H/2][num_conexiones] << endl;
    vector<int> ret (num_conexiones);
    int point = H/2;
    for (int c = num_conexiones; c >= 1; c--) {
        ret[c-1] = dp_radio[point][c];
        point = previous[point][c]; 
    }
    for (auto r : ret) cout << r*2 << "\n";
}