#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int ans = (1<<N) + 1;
  cout << ans * ans;
}