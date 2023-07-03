#include <bits/stdc++.h>

using namespace std;

int num_strings, consecutive, best, final, extra;
string chain;

int main() {
    cin >> num_strings;
    vector<int> ret;
    for (int s = 0; s < num_strings; s++) {
        cin >> chain;
        consecutive = 0; best = 0; final = 0;
        for (int i = 0; i <= 1; i++) {
            for (int a = chain.size()-1; a >= final; a--) {
                if (chain[a] == '1') consecutive++;
                else {
                    best = max(best, consecutive); consecutive = 0;
                }
            }
            final = 1;
        }
        best = max(best, consecutive); consecutive = 0;
        //cout << best << endl;
        if (best == 1) ret.push_back(1);
        else {
            if (best % 2 == 1) ret.push_back(((best/2)+1) * ((best/2)+1));
            else ret.push_back((best/2) * ((best/2)+1));
        }
    }
    for (auto r : ret) cout << r << "\n";
}