#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    for(int i = 0; i < N; ++i) {
        int cnt = 1;
        
        for(int j = 0; j < N; ++j) {
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
                cnt++;
            }
        }
        
        cout << cnt << '\n';
    }
}