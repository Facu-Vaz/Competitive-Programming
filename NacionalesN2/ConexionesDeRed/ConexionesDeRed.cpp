#include <bits/stdc++.h>

using namespace std;

vector<char> ret;
vector<int> sizes;
vector<int> father;

int find (int x)
{
    while (x != father[x]) x = father[x];
    return x;
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a, b);
    sizes[a] += sizes[b];
    father[b] = a;
}


int main(){

    ifstream ifs;
    ifs.open("red.in");
    ofstream ofs;
    ofs.open("red.out");

    char action;
    int a, b;
    for (int i = 0; i <= 1000001; i++) father.push_back(i);
    for (int i = 0; i <= 1000001; i++) sizes.push_back(1);

    while (true) {
        ifs >> action;
        if (action == 'F') break;
        ifs >> a >> b;

        if (action == 'P')
        {
            if (same(a, b)) ret.push_back('S');
            else ret.push_back('N');
        }
        else
        {
            if(!same(a,b)) unite(a, b);
        }
    }

    for (auto r : ret)
    {
        ofs << r << endl;
    }
}