#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    
    int alpha[26];
    fill(alpha, alpha+26, 0);
    
    cin >> input;
    
    for(auto c : input) alpha[c - 'a']++;
    
    for(auto c : alpha) cout << c << ' ';
}