#include <bits/stdc++.h>
using namespace std;

int nums[100'005];
int dp[100'005]; // 1번째 수부터 i번째 수까지 합

int N, M;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
    dp[i] = nums[i] + dp[i-1];
  }
  
  while (M--) {
    int i, j;
    cin >> i >> j;
    cout << dp[j] - dp[i-1] << '\n';
  }
}