#include <bits/stdc++.h>
using namespace std;

/*
오직 '('만 stack에 push

')'을 입력으로 받으면, 이전 괄호와 비교하여
이것이 레이저를 의미하는지 혹은 쇠막대기의 끝을 의미하는지 판별해야 된다.
1. 레이저를 의미하는 경우 = 이전 괄호가 '('인 경우
    stack.pop()
    잘리는 쇠막대기의 개수 = stack.size()
2. 쇠막대기의 끝을 의미하는 경우 = 이전 괄호가 ')'인 경우
    stack.pop()
    잘리는 쇠막대기의 개수 = 1
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    
    stack<char> S;
    int cnt = 0;
    for(int i = 0; i < input.length(); ++i) {
        if(input[i] == '(') S.push(input[i]);
        else { 
            if(input[i-1] == '(') {
                S.pop();
                cnt += S.size();
            }  
            else { 
                S.pop();
                cnt++;
            }
        }
    }
    
    cout << cnt;
}