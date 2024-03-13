#include <bits/stdc++.h>
using namespace std;

int mod = 1000000;
int T = 15*mod/10;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    int arr[T+2];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i < T; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= mod;
    }
    
    cout << arr[n%T];
}