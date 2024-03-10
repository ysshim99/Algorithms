#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    int arr[100];
    for(int i = 0; i < N; ++i) cin >> arr[i];

    int maxSum = 0;

    for(int i = 0; i < N-2; ++i) {
        for(int j = i+1; j < N-1; ++j) {
            for(int k = j+1; k < N; ++k) {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum <= M && maxSum < sum) maxSum = sum;
            }
        }
    }

    cout << maxSum;
}