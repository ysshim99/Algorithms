#include <bits/stdc++.h>
using namespace std;

/*
괄호 쌍 문제와 상당히 유사하다.

각 단어의 문자마다
1. stack이 empty가 아니고, stack의 top이 문자와 동일하면
    stack에서 pop
2. 그 외의 경우라면
    stack에 push

모든 연산 후에 stack이 empty면 좋은 단어이다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, cnt = 0;    
    cin >> N;
    
    while(N--) {
        string input;
        cin >> input;
        
        stack<char> S;
        
        for(auto c : input) {
            if(!S.empty() && S.top() == c) S.pop();
            else S.push(c);
        }
        
        if(S.empty()) cnt++;
    }
    
    cout << cnt;
}