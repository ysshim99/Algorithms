#include <bits/stdc++.h>
using namespace std;

/*
괄호 쌍 문제를 생각하자.

1. `{`
    stack.push
2. `}`
    a. stack.empty
        cnt++
        stack.push(`{`)
    b. !stack.empty() <=> stack에는 `{`만 존재
        stack.pop()

모든 연산 후에 cnt + stack.size/2를 하면 된다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int idx = 1;
    while(true) {
        string input;
        cin >> input;
        
        if(input[0] == '-') break;
        
        stack<char> S;
        int cnt = 0;
        
        for(auto c : input) {
            if(c == '{') S.push(c);
            else if(c == '}') {
                if(S.empty()) {
                    cnt++;
                    S.push('{');
                }
                else S.pop();
            }
        }
        
        cnt += S.size()/2;
        
        cout << idx++ << ". " << cnt << '\n';
    }
}