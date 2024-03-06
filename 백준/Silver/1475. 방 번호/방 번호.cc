#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    int arr[10] = {0, };
    
    while(N) {
        arr[N % 10]++;
        N /= 10;
    }
    
    int max_value = arr[0];
    for(int i = 0; i < 10; ++i) {
        if(i == 6 || i == 9) continue;
        max_value = max(max_value, arr[i]);
    }
    
    max_value = max(max_value, (arr[6]+arr[9]+1)/2);
    
    cout << max_value;
}