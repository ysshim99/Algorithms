#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int result = 1;
    
    for(int i = 1; i <= n; ++i)
        result *= i;
    
    return result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    cout << factorial(N)/(factorial(K)*factorial(N-K));
}