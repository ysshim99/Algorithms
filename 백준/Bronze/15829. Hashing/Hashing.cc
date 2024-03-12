#include <bits/stdc++.h>
using namespace std;

int r = 31;
int M = 1234567891;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L; // 문자열의 길이
    string input; // 소문자로만 이루어진 문자열
    cin >> L >> input;

    int sum = 0;
    for(int i = 0; i < L; ++i) {
        sum += (input[i] - 'a' + 1) * pow(r, i);
    }

    cout << sum % M;
}