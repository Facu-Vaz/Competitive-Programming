#include <bits/stdc++.h>
#define first f
#define second s

using namespace std;

int main()
{
    ifstream ifs("uniformar.in");
    ofstream ofs("uniformar.out");
    
    int N;
    ifs >> N;
    string line;
    vector<vector<int>> paint (N+2, vector<int> (N+2, -1));

    for (int i = 1; i <= N; i++)
    {
        ifs >> line;
        for (int j = 0; j < N; j++)
        {
            paint[i][j+1] = line[j] - 48;
        }
    }

    int max_cost;
    vector<vector<int>> min_x_pixel (N+2, vector<int> (N+2, -1));
    min_x_pixel[1][1] = 0;
    int actual_cost, x, y;
    pair<int, int> cords;
    vector<int> actions {-1, 1};

    deque<pair<int, int>> dq; 
    dq.push_front({1, 1});

    // for (auto a : paint)
    // {
    //     for (auto b : a) cout << b;
    //     cout << endl;
    // }

    while (!dq.empty())
    {
        tie(x, y) = dq.front(); dq.pop_front();
        max_cost = min_x_pixel[y][x];
        //cout << x << " " << y << " - " << min_x_pixel[y][x] << " V: ";
        for (auto action : actions)
        {
            if (min_x_pixel[y][x+action] == -1 && paint[y][x+action] != -1)
            {
                
                if (paint[y][x] == paint[y][x+action]) 
                {
                    min_x_pixel[y][x+action] = min_x_pixel[y][x];
                    dq.push_front({x+action, y});
                    //cout << "A(" << x+action << "," << y << ")  ";
                }
                else 
                {
                    min_x_pixel[y][x+action] = min_x_pixel[y][x] + 1;
                    dq.push_back({x+action, y});
                    //cout << "B(" << x+action << "," << y << ")  ";
                }
            }
            if (min_x_pixel[y+action][x] == -1  && paint[y+action][x] != -1)
            {
                
                if (paint[y][x] == paint[y+action][x]) 
                {
                    min_x_pixel[y+action][x] = min_x_pixel[y][x];
                    dq.push_front({x, y+action});
                    //cout << "A(" << x << "," << y+action << ")";
                }
                else 
                {
                    min_x_pixel[y+action][x] = min_x_pixel[y][x] + 1;
                    dq.push_back({x, y+action});
                    //cout << "B(" << x << "," << y+action << ")";
                }
            }
            //cout << endl;
        }
    }

    ofs << max_cost;

    
}