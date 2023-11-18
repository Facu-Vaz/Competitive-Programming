#include <bits/stdc++.h>

using namespace std;

int N, len_virus;

vector<int> regis;
vector<int> lista;
vector<int> locaciones;

int total = 0;

int main() {

    ifstream cin("polimorfo.in");
    ofstream cout("polimorfo.out");

    cin >> N >> len_virus;

    lista.resize(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> lista[i];
    }

    regis.resize(len_virus+1, 0);
    if (len_virus > N) {
        cout << 0;
        return 0;
    }

    int right = 0;
    int left = 0;
    for (right = 0; right < len_virus; right++) {
        if (lista[right] > 0 && lista[right] <= len_virus) {
            regis[lista[right]]++;
            if (regis[lista[right]] == 1) total++;
        }
    }

    // cout << left << "  " << right << "  " << total << " -  ";
    // for (auto a : regis) {
    //         cout << a << " ";
    //     }
    //     cout << "\n";



    while (right < N) {
        if (lista[left] > 0 && lista[left] <= len_virus) {
            regis[lista[left]]--;
            if (regis[lista[left]] == 0) total--;
            // cout << "REM ";
        }
        left++;

        if (lista[right] > 0 && lista[right] <= len_virus) {
            regis[lista[right]]++;
            if (regis[lista[right]] == 1) total++;
            // cout << "ADD ";
        }
        right++;

        if (total == len_virus) locaciones.push_back(left+1);

        // cout << left << "  " << right << "  " << total << "  -  " << lista[left-1] << "  " << lista[right-1] << "  - ";

        // for (auto a : regis) {
        //     cout << a << " ";
        // }
        // cout << "\n";
    }

    cout << locaciones.size() << endl;
    if (locaciones.size() <= 10) {
        for (auto a : locaciones) cout << a << " ";
    }
    else {
        for (int i = 0; i < 5; i++) cout << locaciones[i] << " ";
        for (int i = locaciones.size()-1; i >= locaciones.size()-5; i--) cout << locaciones[i] << " ";

    }
}