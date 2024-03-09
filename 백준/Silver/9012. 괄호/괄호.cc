#include <bits/stdc++.h>
using namespace std;

/*
1. `(`
    stack.push
2. `)`
    a. stack.empty
        correct = false;
    b. !stack.empty && stack.top == '('
        stack.pop
    c. !stack.empty && stack.top == ')'
        correct = false;
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
        bool correct = true;
        
        for(auto c : input) {
            if(c == '(') S.push(c);
            else {
                if(S.empty()) correct = false;
                else {
                    if(S.top() == '(') S.pop();
                    else correct = false;
                }
            }
        }
        
        if(!S.empty()) correct = false;
        
        if(correct) cout << "YES\n";
        else cout << "NO\n";
    }
}