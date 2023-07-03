#include <bits/stdc++.h>

using namespace std;

vector<int> positions;
vector<int> number_list;
int size_list, temp, num_operations;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> size_list >> num_operations;
    positions.resize(size_list+1);
    number_list.resize(size_list+1);
    for (int i = 1; i <= size_list; i++) {
        cin >> temp; positions[temp] = i;
        number_list[i] = temp;
    }
    
    int actual_pos = positions[1];
    int num_laps = 1;
    for (int i = 2; i <= size_list; i++) {
        if (positions[i] < positions[i-1]) {
            num_laps++;
        }
        actual_pos = positions[i];
    }

    //cout << "Start laps --> " << num_laps << endl << endl;

    vector<int> ret;

    int pos_a, pos_b, num_a, num_b;
    for (int o = 0; o < num_operations; o++) {
        cin >> pos_a >> pos_b;
        //cout << "A";
        num_a = number_list[pos_a]; num_b = number_list[pos_b];
        number_list[pos_a] = num_b; number_list[pos_b] = num_a;
        //cout << "B";
        if (num_b < num_a) {
            swap(num_a, num_b);
            swap(pos_a, pos_b);
        } 
        if (num_a + 1 == num_b) {
            ///cout << "X";
            if (pos_a > pos_b) num_laps++;
            else num_laps--;
        }
        //cout << endl << num_a << " " << pos_a;
        //cout << endl << num_b << " " << pos_b << endl;

        for (int n : {1, 2}) {
            //cout << n;
            if (positions[num_a-1] <= pos_a && positions[num_a-1] >= pos_b) {
                num_laps++;
                //cout << "D";
            }
            else if (positions[num_a-1] >= pos_a && positions[num_a-1] <= pos_b) {
                num_laps--;
                //cout << "E";
            }
            else if (positions[num_a+1] >= pos_a && positions[num_a+1] <= pos_b) {
                num_laps++;
                //cout << "F";
            }
            else if (positions[num_a+1] <= pos_a && positions[num_a+1] >= pos_b) {
                num_laps--;
                //cout << "G";
            }
            swap(num_a, num_b);
            swap(pos_a, pos_b);
        }
        positions[num_a] = pos_b;
        positions[num_b] = pos_a;
        ret.push_back(num_laps);
    }

    for (auto r : ret) cout << r << "\n";

    // cout << endl << endl; 
    // for (auto a : number_list) cout << a << " ";
    // cout << endl << endl;
    // for (auto a : positions) cout << a << " ";
}