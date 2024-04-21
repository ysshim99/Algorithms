#include <bits/stdc++.h>
using namespace std;

int triangle[505][505]; // (1,1) ~ (N, N)
int dp[505][505]; // (i, j)번째 수는 반드시 선택 & 경로 합이 최대

int N;
int ans = 0;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= i; ++j)
      cin >> triangle[i][j];
  
  dp[1][1] = triangle[1][1];
  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j <= i; ++j)
      dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
  }
  
  cout << *max_element(dp[N]+1, dp[N]+N+1);
}