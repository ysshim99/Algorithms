#include <bits/stdc++.h>
using namespace std;

int n;
int A[1005];
int dp[1005]; // 1 ~ i번째 원소에서 중가하는 부분 수열 중 가장 큰 합. 단, i번째 원소는 반드시 포함해야 됨

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    dp[i] = A[i];
  }
      
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (A[j] < A[i]) dp[i] = max(dp[i], dp[j] + A[i]);
    }
  }

  cout << *max_element(dp, dp + n);
}