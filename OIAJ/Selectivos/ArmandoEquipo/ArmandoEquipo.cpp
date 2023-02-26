#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("equipo.in");
    ofstream cout("equipo.out");

    int preguntas_num, colaboradores_num;
    cin >> preguntas_num >> colaboradores_num;

    map<char, int> starts;
    vector<vector<int>> adjs (2500001, vector<int>());
    vector<char> num_to_char (2500001, '0');
    vector<int> num_to_participants (2500001, 0);
    string coincidence = "";

    int num_nodes = 0;
    int actual_node, prev_node;
    char actual_char;
    int max_afinidad = 0; 
    bool found; 
    string answers;

    for (int c = 0; c < colaboradores_num; c++)
    {
        answers = "";
        cin >> actual_char;
        answers += actual_char;
        //cout << actual_char;

        if (starts.count(actual_char) == 0)
        {
            actual_node = num_nodes;
            starts[actual_char] = actual_node;
            num_nodes++;
        }
        else actual_node = starts[actual_char];

        num_to_participants[actual_node]++;

        if (num_to_participants[actual_node] > 1) 
        {
            if (num_to_participants[actual_node] > max_afinidad)
            {
                max_afinidad = num_to_participants[actual_node];
                coincidence = actual_char;
            }
            //cout << "A";
        }

        for (int p = 1; p < preguntas_num; p++)
        {
            cin >> actual_char; prev_node = actual_node;
            //cout << actual_char;

            answers += actual_char;
            found = false;

            for (int adj : adjs[prev_node])
            {
                if (num_to_char[adj] == actual_char) {
                    actual_node = adj;
                    found = true;
                    //cout << "ACAA";
                }
            }
            if (!found) 
            {
                actual_node = num_nodes;
                adjs[prev_node].push_back(actual_node);
                num_to_char[actual_node] = actual_char;
                num_nodes++;
            }

            num_to_participants[actual_node]++;

            if (num_to_participants[actual_node] > 1) {
                if (num_to_participants[actual_node] * (p+1) * (p+1) > max_afinidad)
                {
                    max_afinidad = num_to_participants[actual_node] * (p+1) * (p+1);
                    coincidence = "";
                    for (char a : answers)
                    {
                        coincidence += a;
                    }
                   //cout << endl << "DONE " << answers << " " << max_afinidad << endl; 
                }
                //cout << "B";
            }
        }

        //cout << " FINISH "<< endl;
    }
    cout << max_afinidad << endl << coincidence;
}