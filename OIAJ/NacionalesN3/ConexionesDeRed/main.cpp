#include <bits/stdc++.h>

using namespace std;

vector<int> father;
vector<int> fam_size;
char q;
int ga, gb;


int find (int x) {
    while (father[x] != x) x = father[x];
    return x;
}

bool same (int a, int b) {
    return find(a) == find(b);
}

void join (int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (fam_size[b] > fam_size[a]) swap(a, b);
        father[b] = a;
        fam_size[a] += fam_size[b];
    }
}


int main() {

    ifstream cin("conectar.in");
    ofstream cout("conectar.out");

    cin >> q;
    fam_size.resize(1e7+1, 1);
    father.resize(1e7+1);
    for (int i = 0; i <= 1e7; i++) father[i] = i;
    while (q != 'F') {
        cin >> ga >> gb;

        if (q == 'P') {
            if (same(ga, gb)) cout << "S" << endl;
            else cout << "N" << endl;
        }
        else join(ga, gb);
        cin >> q;
    }
}