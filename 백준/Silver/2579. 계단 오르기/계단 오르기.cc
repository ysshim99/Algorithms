#include <bits/stdc++.h>
using namespace std;

int stairs[305];
int dp[305]; // i번째 계단을 반드시 밟고, 총 점수의 최댓값을 의미

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 1; i <= N; ++i) cin >> stairs[i];
  
  dp[1] = stairs[1];
  dp[2] = stairs[2] + stairs[1];
  dp[3] = stairs[3] + max(stairs[2], stairs[1]);
  for (int i = 4; i <= N; ++i)
    dp[i] = stairs[i] + max(stairs[i-1] + dp[i-3], dp[i-2]);
  
  cout << dp[N];
}