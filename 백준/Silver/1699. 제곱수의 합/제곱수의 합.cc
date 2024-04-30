#include <bits/stdc++.h>
using namespace std;

int dp[100'005]; // dp[i] = i를 제곱수의 합으로 나타날 때, 제곱수 항의 최소 개수

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  // initialization
  for (int i = 1; i <= N; ++i) dp[i] = dp[i-1] + 1;
  
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j*j <= i; ++j) {
      dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
  }
  
  cout << dp[N];
}