#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int A, B, C;

ll POW(int a, int b, int c) {
    if(b == 0) return 1;
    
    ll val = POW(a, b/2, c);
    val = val * val % c;
    
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B >> C;
    
    cout << POW(A, B, C);
}