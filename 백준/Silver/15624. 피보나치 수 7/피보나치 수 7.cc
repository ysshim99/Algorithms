#include <bits/stdc++.h>
using namespace std;

int M = 1000000007;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int arr[n+2];
    arr[0] = 0;
    arr[1] = 1;
    
    for(int i = 2; i <= n; ++i) {
        arr[i] = (arr[i-1] + arr[i-2]) % M;
    }
    
    cout << arr[n];
}