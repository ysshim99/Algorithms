#include <bits/stdc++.h>
using namespace std;

int dp[50005]; // dp[i]: i를 최소 개수의 제곱수 합으로 표현할 수 있음

int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i-1] + 1;
    for (int j = 1; j*j <= i; ++j) {
      dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
  }
  
  cout << dp[n];
}