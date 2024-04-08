#include <bits/stdc++.h>
using namespace std;

int exited[10], boarded[10];
int ans, total;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < 10; ++i) {
    cin >> exited[i] >> boarded[i];
    total = total - exited[i] + boarded[i];
    ans = max(ans, total);
  }
  
  cout << ans;
}