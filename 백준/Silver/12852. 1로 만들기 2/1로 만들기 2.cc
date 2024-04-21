#include <bits/stdc++.h>
using namespace std;

int dp[1'000'005];
int pre[1'000'005]; // i번째 수를 최소의 연산으로 만들기 위한 직전값. 예를 들어, dp[10] = 9

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  dp[1] = 0;
  pre[1] = 0;
  for (int i = 2; i <= N; ++i) {
    dp[i] = dp[i-1] + 1;
    pre[i] = i-1;
    
    if (i % 2 == 0 && dp[i] > dp[i/2] + 1) {
      dp[i] = dp[i/2] + 1;
      pre[i] = i/2;
    }
    
    if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
      dp[i] = dp[i/3] + 1;
      pre[i] = i/3;
    }
  }
  
  cout << dp[N] << '\n';
  
  // N을 1로 만드는 방법 출력
  int cur = N;
  while (true) {
    cout << cur << ' ';
    
    if (cur == 1) break;
    cur = pre[cur];
  }  
}