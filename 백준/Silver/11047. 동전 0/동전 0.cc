#include <bits/stdc++.h>
using namespace std;

int coins[15];

int N, K;
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for (int i = 0; i < N; ++i) cin >> coins[i];
  
  for (int i = N-1; i >= 0; --i) {
    ans += K / coins[i];
    K %= coins[i];
  }
  
  cout << ans;
}