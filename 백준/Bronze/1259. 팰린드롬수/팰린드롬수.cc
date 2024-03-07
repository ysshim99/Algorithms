#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        string input;
        cin >> input;
        
        if(input == "0") break;
        
        string R = input;
        reverse(input.begin(), input.end());
        
        if(input == R) cout << "yes\n";
        else cout << "no\n";
    }
}