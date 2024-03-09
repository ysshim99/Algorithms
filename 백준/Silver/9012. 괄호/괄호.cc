#include <bits/stdc++.h>
using namespace std;

/*
1. `(`
    stack.push
2. `)`
    a. stack.empty
        correct = false;
    b. !stack.empty && stack.top == ')'
        correct = false;
        break;
    c. !stack.empty && stack.top == '('
        stack.pop

*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        string input;
        cin >> input;
        
        stack<char> S;
        bool isValid = true;
        
        for(auto c : input) {
            if(c == '(') S.push(c);
            else {
                if(S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }
        
        if(!S.empty()) isValid = false;
        
        if(isValid) cout << "YES\n";
        else cout << "NO\n";
    }
}