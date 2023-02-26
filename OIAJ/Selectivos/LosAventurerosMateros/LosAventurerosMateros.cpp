#include <bits/stdc++.h>

using namespace std;

vector<int> segTree;
int pasos;
int N, num_materos;

void remove (int x) {
    x += N;
    segTree[x] = 0; x /= 2;
    while (x != 0)
    {
        segTree[x] = segTree[x*2] + segTree[x*2+1];
        x /= 2;
    }
}


int sum (int a, int b) {
    a += N; b += N; int s = 0;
    if (a == b) return segTree[a];
    while (a <= b) {
        if (a%2 == 1) s += segTree[a++];
        if (b%2 == 0) s += segTree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

int look_for (int x) {
    int s = segTree[1]; int p = 1;
    while (p < N)
    {
        //cout << "|" << p << "|" << "";
        if (x >= segTree[p] - segTree[p*2+1]) {
            x -= segTree[p*2];
            p = p*2+1;
        }
        else p = p*2;
    }
    //cout << "|" << p << "|" << endl;
    return p-N;
}

int main ()
{
    ifstream cin("aventureros1.in");
    //ofstream cout("aventureros.out");
    
    cin >> num_materos; 
    
    N = 1;
    while (N < num_materos)
    {
        N *= 2;
    } 
    segTree.resize(N*2, 0);
    for (int i = 0; i < num_materos; i++) segTree[i+N] = 1;
    for (int i = N-1; i > 0; i--) segTree[i] = segTree[i*2] + segTree[i*2+1];

    // for (auto a : segTree) cout << a << " ";
    // cout << endl;

    int start = 0; int rem, next;
    vector<int> ret; 
    for (int i = 1; i < num_materos; i++) {
        cin >> pasos; 
        //pasos = pasos % segTree[1];
        pasos = ((sum(0, start) + pasos) - 1) % segTree[1];
        //pasos = (pasos == segTree[1]) ? pasos : pasos % segTree[1];
        next = look_for(pasos); remove(next);
        ret.push_back(next+1);
        start = look_for(pasos % segTree[1]);
        //cout << pasos << " - " << next+1 << " - " << start+1 << " - " << segTree[1] << endl;
    }

    for (auto a : ret) cout << a << " ";
    cout << endl << look_for(0)+1 << endl;
    

}