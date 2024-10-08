#include <bits/stdc++.h>
using namespace std;

int t, n;
long long ans;

int nums[105];

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j)
        ans += gcd(nums[i], nums[j]);
    
    cout << ans << '\n';
  }
}
