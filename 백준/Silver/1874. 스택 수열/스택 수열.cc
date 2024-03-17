#include <bits/stdc++.h>
using namespace std;

stack<int> s;   // 현재 스택 상태
vector<char> v; // '+', '-' 필요한 연산 저장

int n, num = 1; // num: 1~n 까지의 수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; ++i) {
        int input;
        cin >> input;

        while(num <= input) {
            s.push(num++);
            v.push_back('+');
        }

        if(s.top() == input) {
            s.pop();
            v.push_back('-');
        }

        else {
            cout << "NO";
            return 0;
        }
    }

    for(auto c : v) cout << c << '\n';
}