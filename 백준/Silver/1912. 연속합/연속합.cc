#include <bits/stdc++.h>
using namespace std;

int dp[100'005]; // i번째 원소로 끝나는 연속합 중 최대
int nums[100'005];

int n;
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 1; i <= n; ++i) { 
    cin >> nums[i];
    dp[i] = max(0, dp[i-1]) + nums[i];
  }
  
  cout << *max_element(dp+1, dp+1+n);
}