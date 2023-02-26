#include <bits/stdc++.h>

using namespace std;

int medir(string cad);

int floors = 0;
int temp = 1;

int mid;

string count_chars(char a)
{
    string test = "";
    bool prev;
    int margin = mid/2;
    for (int i = 0; i < mid; i++) test.push_back(a);
    for (int f = 0; f < floors; f++)
        {
            if (margin == 0)
            {
                if (!prev) 
                {
                    if (!medir(test)) test.pop_back();
                }
                else
                {
                    if (!medir(test)) test.pop_back();
                }
            }
            else
            {
                prev = medir(test);
                if (prev) for (int i = 0; i < margin; i++) test.push_back(a);
                else for (int i = 0; i < margin; i++) test.pop_back();
                margin /= 2;
            }
        }
    return test;
}

string secuenciar(int N, string s)
{
    string ret;
    floors = 0;
    temp = 1;
    while (temp < N) 
    {
        temp *= 2;
        floors++;
    }
    mid = temp / 2;
    if (s == "AC")
    {
        ret = count_chars('A');
        int left = N - ret.size();
        for (int i = 0; i < left; i++) ret.push_back('C');
    } 
    else 
    {
        int num_capas = 0;
        int ancho = 1;
        while (ancho < s.size())
        {
            ancho *= 2;
            num_capas++;
        }
        vector<vector<string>> vec (num_capas);
        for(int i = 0; i < s.size(); i++)
        {
            vec[0].push_back(count_chars(s[i]));
        }
        int j = 0;
        for(int i = 1; i < num_capas; i++)
        {
            j = 0;
            while (j*2 < vec[i-1].size())
            {
                
            }
            
        }



        for (auto a : vec[0])
        {
            for (auto b : a)
            {
                cout << b;
            }
            cout << endl;
        }
    }

    return ret;
}
