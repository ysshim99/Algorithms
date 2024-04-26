#include <bits/stdc++.h>
using namespace std;

int A[1005];
int dp[1005]; // 1 ~ i번째 원소에서 가장 긴 부분 수열의 길이. 단, i번째 원소는 반드시 포함해야 됨

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
    dp[i] = 1;
  }
  
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  
  cout << *max_element(dp, dp+N);
}
