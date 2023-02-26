#include <bits/stdc++.h>

using namespace std;

int len, max_operations;
vector<int> numbers;

int main ()
{
    ifstream cin("input.in");
    
    cin >> len >> max_operations;
    numbers.resize(len, 0);
    for (int i = 0; i < len; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end()); 

    int half = len/2;
    int left = max_operations; 
    int ret = numbers[half];
    int at_a_time = 1;
    int top = -1;

    while (true)
    {
        top = min(half+at_a_time, len-1);
        if (numbers[top] == ret) 
        {
            at_a_time++; 
            if (top  != len-1) continue;
        }
        if (left-at_a_time >= 0) {
            ret++;
            left -= at_a_time;
        }
        else break;
    }
    cout << ret;
}