#include <bits/stdc++.h>
using namespace std;

long long dp[100][2]; // dp[i][0] : 가장 오른쪽 숫자 = 0, dp[i][1] : 가장 오른쪽 숫자 = 1

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  dp[1][0] = 0;
  dp[1][1] = 1;
  for (int i = 2; i <= N; ++i) {
    dp[i][0] = dp[i-1][0] + dp[i-1][1];
    dp[i][1] = dp[i-1][0];
  }
  
  cout << dp[N][0] + dp[N][1];
}