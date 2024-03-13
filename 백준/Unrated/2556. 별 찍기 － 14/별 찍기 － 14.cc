#include <bits/stdc++.h>
using namespace std;

/*
꽉 찬 ㅁ자 형태를 출력하는 문제이다.
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) cout << '*';
        cout << '\n';
    }
}