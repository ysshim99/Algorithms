#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b, int m) {
    if(b == 0) return 1;
    if(b == 1) return a % m;
    
    long long val = power(a, b/2, m);
    val = val * val % m;
    if(b % 2 == 0) return val;
    else return val*a % m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << power(A, B, C);
}