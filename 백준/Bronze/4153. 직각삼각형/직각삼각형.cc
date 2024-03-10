#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 0) return 0;
        
        if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) cout << "right\n";
        else cout << "wrong\n";
    }
}