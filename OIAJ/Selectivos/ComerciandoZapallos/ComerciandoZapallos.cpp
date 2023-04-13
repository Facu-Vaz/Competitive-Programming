#include <bits/stdc++.h>

using namespace std;

int num_vendedores, espacio, total_zapallos;
int current_zapallos, temp;
vector<int> checkpoints;
vector<int> zapallos;
vector<vector<int>> dp;
vector<vector<int>> num_agarrados;

int main () 
{
    ifstream cin("zapallos.in");
    //ofstream cout("zapallos.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    total_zapallos = 0;
    cin >> num_vendedores >> espacio;
    checkpoints.resize(num_vendedores+1, 1);
    for (int v = 1; v <= num_vendedores; v++) {
        cin >> current_zapallos;
        total_zapallos += current_zapallos;
        for (int z = 0; z < current_zapallos; z++) {
            cin >> temp;
            if (z > 0) {
                zapallos.push_back(zapallos[zapallos.size()-1] + (10-temp));
            }
            else zapallos.push_back(10-temp);
        }
        checkpoints[v] = checkpoints[v-1] + current_zapallos;
    }
    dp.resize(espacio+1, vector<int> (total_zapallos+1, 0));
    num_agarrados.resize(espacio+1, vector<int> (total_zapallos+1, 0));
    int better, option_2, point;
    int current_espacio = 0;
    for (int e = 1; e <= espacio; e++) {
        point = 0; current_espacio = 0;
        for (int z = 1; z <= total_zapallos; z++) {
            current_espacio++;
            if (z >= checkpoints[point+1]) {
                point++; current_espacio = 1;
            }
            if (current_espacio > e) {
                dp[e][z] = dp[e][z-1];
                if (current_espacio != 1) num_agarrados[e][z] = num_agarrados[e][z-1];
            }
            else {
                better = dp[e][z-1]; 
                option_2 = dp[e-current_espacio][checkpoints[point]-1] + zapallos[z-1];
                if (option_2 > better) {
                    better = option_2;
                    num_agarrados[e][z] = current_espacio;
                }
                else if (current_espacio != 1) num_agarrados[e][z] = num_agarrados[e][z-1];
                dp[e][z] = better;
            }
        }
    }

    for (auto a : dp) {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }
    cout << endl;
    for (auto a : num_agarrados) {
        for (auto b : a) cout << b << " ";
        cout << endl;
    }
    cout << endl;

    int e = espacio;
    int sum = 0;
    vector<int> ret;
    for (int c = checkpoints.size()-1; c > 0; c--) {
        ret.push_back(num_agarrados[e][checkpoints[c]-1]);
        sum += num_agarrados[e][checkpoints[c]-1];
        //cout << num_agarrados[e][checkpoints[c]-1] << endl;
        e -= num_agarrados[e][checkpoints[c]-1];
    }

    cout << dp[espacio][total_zapallos] << " " << sum << endl;
    for (int i = ret.size()-1; i >= 0; i--) {
        cout << ret[i] << " ";
    }
}