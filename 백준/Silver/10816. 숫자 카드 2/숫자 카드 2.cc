#include <bits/stdc++.h>
using namespace std;

/*
배열을 정렬 -> 이분 탐색 수행
upper_bound: num 이상의 값이 처음 나타나는 위치
lower_bound: num을 초과하는 값이 처음 나타나는 위치
*/

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int arr[500000];
    for(int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr+N);
    
    int M;
    cin >> M;
    
    for(int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        
        cout << upper_bound(arr, arr+N, num) - lower_bound(arr, arr+N, num) << ' ';
    }
}