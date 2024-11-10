#include <stack>
#include <string>

using namespace std;

int solution(string s) {
    stack<char> stk;
    
    for (int i = 0; i < s.length(); ++i) {
        // 스택이 비어 있거나 현재 문자와 같은 문자가 아니면 푸시
        if (stk.empty() || stk.top() != s[i])
            stk.push(s[i]);
        // 현재 문자와 스택의 가장 최근 문자가 같으면 팝
        else
            stk.pop();
    }
    
    // 현재 스택이 비어 있다 = 문자열의 짝이 맞다
    return stk.empty();
}