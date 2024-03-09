#include <bits/stdc++.h>
using namespace std;

/*
`(()[[]])`을 예로 들면, sum = 2*2 + 2*3*3 임을 알 수 있다.
이는 `(())([[]])`와 동치이다.

즉, `(`을 만나면 곱해질 값이 2배 증가하고,
    `[`을 만나면 곱해질 값이 3배 증가하므로
이를 num 변수를 이용해서 표현하면 된다.

1. `(` 혹은 `[`
    num에 2 혹은 3을 곱하고, stack에 push한다.
2. `)`
    stack이 empty이거나 stack의 top이 `(`가 아니라면 올바르지 않은 괄호열이다.
    직전 괄호가 `(`였다면 sum에 num 추가
    이후에 stack을 pop, num을 2로 나눈다.
3. `]`
    stack이 empty이거나 stack의 top이 `[`가 아니라면 올바르지 않은 괄호열이다.
    직전 괄호가 `[`였다면 sum에 num 추가
    이후에 stack을 pop, num을 3으로 나눈다.

모든 연산 후에 스택에 남아있는 값이 있다면 올바르지 않은 괄호열이다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    
    int sum = 0;
    int num = 1;
    stack<char> S;
    
    for(int i = 0; i < (int)input.length(); ++i) {
        if(input[i] == '(') {
            num *= 2;
            S.push(input[i]);
        }
        else if(input[i] == '[') {
            num *= 3;
            S.push(input[i]);
        }
        else if(input[i] == ')') {
            if(S.empty() || S.top() != '(') {
                cout << 0;
                return 0;
            }
            if(input[i-1] == '(') sum += num;
            S.pop();
            num /= 2;
        }
        else if(input[i] == ']') {
            if(S.empty() || S.top() != '[') {
                cout << 0;
                return 0;
            }
            if(input[i-1] == '[') sum += num;
            S.pop();
            num /= 3;
        }
    }
    
    if(S.empty()) cout << sum;
    else cout << 0;
    
}
