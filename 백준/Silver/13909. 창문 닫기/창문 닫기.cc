#include <bits/stdc++.h>
using namespace std;

int N;
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for(int i = 1; i*i <= N; ++i) {
    ans++;
  }
  cout << ans;
}