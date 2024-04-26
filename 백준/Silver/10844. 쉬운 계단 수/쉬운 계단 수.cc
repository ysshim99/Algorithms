#include <bits/stdc++.h>
using namespace std;

int dp[105][10]; // dp[i][j]: j로 끝나는 길이가 i인 계단 수

const int M = 1'000'000'000;
int N;
long long ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 1; i < 10; ++i) dp[1][i] = 1;
  for (int i = 2; i <= N; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j != 0) dp[i][j] += dp[i-1][j-1];
      if (j != 9) dp[i][j] += dp[i-1][j+1];
      dp[i][j] %= M;
    }
  }
  
  for (int i = 0; i < 10; ++i) ans += dp[N][i];
  cout << ans % M;
}