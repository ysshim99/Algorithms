#include <bits/stdc++.h>
using namespace std;

string X, Y;

int LCSLength(const string& X, const string& Y) {
  int m = X.length();
  int n = Y.length();
  
  int dp[m+1][n+1]; // dp[i][j] = X[i-1], Y[j-1]까지 비교
  
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (X[i-1] == Y[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  
  return dp[m][n];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> X >> Y;
  
  cout << LCSLength(X, Y);
}