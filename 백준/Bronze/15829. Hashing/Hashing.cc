#include <bits/stdc++.h>
using namespace std;

long long r = 1;
int M = 1234567891;
long long hashValue;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L; // 문자열의 길이
    string input; // 소문자로만 이루어진 문자열
    cin >> L >> input;

    for(int i = 0; i < L; ++i) {
        hashValue += ((input[i] - 'a' + 1) * r) % M;
        hashValue %= M;
        r = (r * 31) % M;
    }

    cout << hashValue;
}