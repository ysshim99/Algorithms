#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int P;
    cin >> P;
    
    while(P--) {
        int N, M;
        cin >> N >> M;
        
        int cnt = 0;
        int a = 0, b = 1;
        while(1) {
            int tmp = (a + b) % M;
            a = b;
            b = tmp;
            cnt++;
            
            if(a == 0 && b == 1) break;
        }
        
        cout << N << ' ' << cnt << '\n';
    }
}