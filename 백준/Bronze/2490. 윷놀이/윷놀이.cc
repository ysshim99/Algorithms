#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3; ++i) {
        int arr[4];
        for(int j = 0; j < 4; ++j) cin >> arr[j];
        
        sort(arr, arr+4);
        
        if(arr[3] == 0) cout << 'D';
        else if(arr[2] == 0) cout << 'C';
        else if(arr[1] == 0) cout << 'B';
        else if(arr[0] == 0) cout << 'A';
        else cout << 'E';
        cout << '\n';
    }
}