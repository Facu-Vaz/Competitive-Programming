#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("mural.in");
    ofstream cout("mural.out");
    
    map<char, int> primary{{'R', 0}, {'Z', 1}, {'A', 2}};
    vector<vector<char>> combine {
        {'R', 'P', 'N'},
        {'P', 'Z', 'V'},
        {'N', 'V', 'A'}
    };

    int n;
    cin >> n;

    vector<vector<char>> paint (n+1, vector<char> (n+1, '.'));

    int verticales_num, horizontales_num;
    cin >> horizontales_num >> verticales_num;
    int z, a, b;
    char color;

    for (int i = 0; i < horizontales_num; i++)
    {
        cin >> z >> color >> a >> b;
        for (int j = a; j <= b; j++)
        {
            if (paint[z][j] == '.') paint[z][j] = color;
            else 
            {
                paint[z][j] = combine[ primary[paint[z][j]] ] [ primary[color] ];
            }
        }
    }

    for (int i = 0; i < verticales_num; i++)
    {
        cin >> z >> color >> a >> b;
        for (int j = a; j <= b; j++)
        {
            if (paint[j][z] == '.') paint[j][z] = color;
            else 
            {
                paint[j][z] = combine[ primary[paint[j][z]] ] [ primary[color] ];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << paint[i][j];
        }
        cout << endl;
    }
}