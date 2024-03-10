#include <bits/stdc++.h>
using namespace std;

bool isPrime(int p) {
    if(p == 1) return false;
    for(int i = 2; i * i <= p; ++i)
        if(p % i == 0) return false;
    
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int cnt = 0;
    
    while(N--) {
        int num;
        cin >> num;
        
        if(isPrime(num)) cnt++;
    }
    
    cout << cnt;
}