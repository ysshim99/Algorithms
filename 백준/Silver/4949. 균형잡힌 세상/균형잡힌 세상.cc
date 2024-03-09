#include <bits/stdc++.h>
using namespace std;

/*
1. 여는 괄호가 나오면 스택에 push
2. 닫는 괄호가 나오면,
   a. 스택이 비어있으면 isValid = false
   b. 스택의 top이 짝이 맞지 않으면 isValid = false
   c. 스택의 top이 맞으면 isValid = true
3. 모든 과정을 끝낸 후, 
   a. 스택이 비어있으면 isValid = true
   b. 스택이 비어있지 않으면 isValid = false;
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        string input;
        getline(cin, input);
        
        if(input == ".") break;
        
        stack<char> S;
        bool isValid = true;
        for(auto c : input) {
            if(c == '(' || c == '[') S.push(c);
            else if(c == ')') {
                if(S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                
                S.pop();
            }
            else if(c == ']') {
                if(S.empty() || S.top() != '[') {
                    isValid = false;
                    break;
                }
                
                S.pop();
            }
        }
        
        if(!S.empty()) isValid = false;
        
        if(isValid) cout << "yes\n";
        else cout << "no\n";
    }
}