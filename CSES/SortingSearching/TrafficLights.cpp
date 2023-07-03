#include <bits/stdc++.h>

using namespace std;

int size_street, num_ligths;

int main() {
    set<int> ligths; 
    multiset<int> periods;

    cin >> size_street >> num_ligths;
    ligths.insert(0); ligths.insert(size_street);
    periods.insert(size_street);

    int actual_ligth, rigth, left;
    set<int>::iterator iter;
    for (int l = 0; l < num_ligths; l++) {
        cin >> actual_ligth; ligths.insert(actual_ligth);
        iter = ligths.find(actual_ligth);
        left = *prev(iter); rigth = *next(iter);
        left =  actual_ligth - left; 
        rigth = rigth - actual_ligth;
        periods.erase(periods.find(left+rigth));
        periods.insert(left); periods.insert(rigth);
        cout << *periods.rbegin() << "\n";
    } 
}