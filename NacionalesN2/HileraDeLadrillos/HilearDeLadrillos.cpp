#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("ladrillos.in");
    ofstream ofs;
    ofs.open("ladrillos.out");

    int n;
    int num_valores = 0;
    ifs >> n;
    vector<string> ladrillos (n);
    for (int l = 0; l < n; l++)
    {
        ifs >> ladrillos[l];
        if (ladrillos[l] != "*") num_valores++;
    }

    vector<int> ret (n);

    if (num_valores == 0){
        for (int i = 0; i < ret.size(); i++) ret[i] = 0;
    }

    else if (num_valores == 1)
    {
        int point, start_r, start_l;
        for (int i = 0; i < n; i++)
        {
            if (ladrillos[i] != "*") {
                point = i;
                ret[point] = stoi(ladrillos[point]);
                break;
            }
        }
        if (point == n-1)
        {
            ret[point-1] = -ret[point];
            start_l = point-2;
            start_r = point+1;
        }
        else
        {
            ret[point+1] = 0;
            start_l = point-1;
            start_r = point+2;
        }
        cout << start_l << " " << start_r << endl << "AA";
        for (int i = start_r; i < n; i++)
        {
            ret[i] = ret[i-1] + ret[i-2];
            //cout << ret[i] << endl;
        }
        for (int i = start_l; i >= 0; i--)
        {
            ret[i] = ret[i+2] - ret[i+1];
            //cout << ret[i] << endl;
        }
        cout << point << endl;
    }

    else
    {
        int point, start_r, start_l;
        bool second = false;
        for (int i = 0; i < n; i++) {
            if (ladrillos[i] != "*") {
                if (!second) {
                    start_l = i;
                    ret[start_l] = stoi(ladrillos[start_l]);
                    second = true;
                }
                else {
                    start_r = i;
                    ret[start_r] = stoi(ladrillos[start_r]);
                    break;
                }
            }
        }
        int l = start_r - start_l;
        int a;
        vector<int> temp (l+1);
        cout << "AA" << endl;
        if (l != 0)
        {
            temp[0] = 0;
            if (l > 1)
            {
                temp[1] = 1;
                for (int i = 2; i < temp.size(); i++)
                {
                    temp[i] = temp[i-1] + temp[i-2];
                }
                a = (ret[start_r] - temp[temp.size()-2] * ret[start_l]) /  temp[temp.size()-1];
            }
            else a = ret[start_r] - ret[start_l];

            ret[start_l + 1] = a;

            for (int i = start_l + 2; i < start_r; i++) ret[i] = ret[i-1] + ret[i-2];
        }

        for (int i = start_r; i < n; i++) ret[i] = ret[i-1] + ret[i-2];
        for (int i = start_l; i >= 0; i--) ret[i] = ret[i+2] - ret[i+1];
    }

    for (auto r : ret)
    {
        ofs << r << " ";
    }
}
