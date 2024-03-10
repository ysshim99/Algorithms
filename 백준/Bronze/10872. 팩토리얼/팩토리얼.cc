#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    if(N == 0) cout << 1;
    else {
        int result = 1;
        
        for(int i = 1; i <= N; ++i) result *= i;
        
        cout << result;
    }
}