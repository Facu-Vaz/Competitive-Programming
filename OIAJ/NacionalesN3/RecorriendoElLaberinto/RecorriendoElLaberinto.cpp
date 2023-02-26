#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("tabiques.in");
    ofstream ofs;
    ofs.open("tabiques.out");
    
    int heigth, width;
    ifs >> width >> heigth;
    int num_baldosas = width*heigth;
    vector<vector<int>> neighbours (num_baldosas, vector<int> (4, 1));
    for (int n = 0; n < num_baldosas; n += width) neighbours[n][0] = -1;
    for (int n = 0; n < width; n++) neighbours[n][1] = -1;
    for (int n = width-1; n < num_baldosas; n += width) neighbours[n][2] = -1;
    for (int n = num_baldosas-width; n < num_baldosas; n++) neighbours[n][3] = -1;
    int num_tabiques;
    ifs >> num_tabiques;
    int x1, y1, x2, y2, base;
    bool vertical;
    for (int t = 0; t < num_tabiques; t++)
    {
        ifs >> x1 >> y1 >> x2 >> y2;
        vertical = x1 == x2;
        if (vertical)
        {     
            for (int y = y1; y < y2; y++)
            {
                neighbours[x1 + (y * width) - 1][2] = -1;
                neighbours[x1 + (y * width)][0] = -1;
            }
        }
        else 
        {
            for (int x = x1; x < x2; x++)
            {
                neighbours[x + (y1-1) * width][3] = -1;
                neighbours[x + y1 * width][1] = -1;
            }
        }
    }
    vector<int> distance (num_baldosas, -1);
    distance[0] = 0;
    queue<int> q; q.push(0);
    bool done = false;
    int actual_cell;
    vector<int> move = {-1, -width, 1, width};
    while (!q.empty() && !done)
    {
        actual_cell = q.front(); q.pop();
        for (int n = 0; n < 4; n++)
        {
            if (neighbours[actual_cell][n] == 1 && distance[actual_cell+move[n]] == -1)
            {
                distance[actual_cell+move[n]] = distance[actual_cell] + 1;
                if (actual_cell+move[n] == num_baldosas-1)
                {
                    done = true;
                    break;
                }
                q.push(actual_cell+move[n]);
            }
        }
    }
    if (!done) ofs << "imposible";
    else ofs << distance[num_baldosas-1];
}