#include <bits/stdc++.h>
using namespace std;

int cost[1005][3];
int dp[1005][3]; // N번째 집은 i번째 색으로 칠할 때, 비용의 최솟값

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 1; i <= N; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> cost[i][j];
  
  dp[1][0] = cost[1][0], dp[1][1] = cost[1][1], dp[1][2] = cost[1][2];
  for (int i = 2; i <= N; ++i) {
    dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);
    dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);
    dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
  }
  
  cout << *min_element(dp[N], dp[N]+3);
}