#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    
    int alpha[26] = {0, };
    
    for(auto c : a) alpha[c - 'a']++;
    for(auto c : b) alpha[c - 'a']--;
    
    int absSum = 0;
    for(auto i : alpha) absSum += abs(i);
    
    cout << absSum;
}