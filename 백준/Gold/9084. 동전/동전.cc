#include <bits/stdc++.h>
using namespace std;

int coins[25];
int dp[10005]; // dp[i]: 금액 i원을 만드는 모든 방법의 수

int T, N, M;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  
  while (T--) {
    // initialization
    fill(dp, dp+10005, 0);
    
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> coins[i];
    
    cin >> M;
    
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = coins[i]; j <= M; ++j) {
        dp[j] += dp[j - coins[i]];
      }
    }
    
    cout << dp[M] << '\n';
  }
}