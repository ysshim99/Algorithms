#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int arr[2000001] = {0, };
    for(int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        
        arr[input]++;
    }
    
    int x;
    cin >> x;
    
    int cnt = 0;
    for(int i = 0; i < (x+1)/2; ++i) {
        if(arr[i] == 1 && arr[x-i] == 1) cnt++;
    }
    
    cout << cnt;
}