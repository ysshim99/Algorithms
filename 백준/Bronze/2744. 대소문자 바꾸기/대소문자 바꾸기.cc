#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    
    for(auto c : input) {
        if(c < 'a') cout << char(c + ('a' - 'A'));
        else cout << char(c - ('a' - 'A'));
    }
}