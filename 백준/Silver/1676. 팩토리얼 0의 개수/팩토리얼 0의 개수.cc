#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int cnt = 0;
    
    while(N > 0) {
        cnt += N/5;
        N /= 5;
    }
    
    cout << cnt;
}