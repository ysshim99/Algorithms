#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    int arr[100000];

    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];

    sort(arr, arr+N);

    cin >> M;
    for(int i = 0; i < M; ++i) {
        int num;
        cin >> num;

        cout << binary_search(arr, arr+N, num) << '\n';
    }
}