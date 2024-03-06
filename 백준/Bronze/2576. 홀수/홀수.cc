#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[7];
    for(int i = 0; i < 7; ++i) cin >> arr[i];
    
    int result[7];
    int idx = 0;
    for(int i = 0; i < 7; ++i)
        if(arr[i] % 2 == 1) result[idx++] = arr[i];
    
    sort(result, result+idx);
    
    int sum = 0;
    for(int i = 0; i < idx; ++i) sum += result[i];
    
    if(idx == 0) cout << -1;
    else cout << sum << '\n' << result[0];
}