#include <bits/stdc++.h>
using namespace std;

int N;
int ans;

int func(int N) {
  int sum = N/10 + N%10;
  return (N%10)*10 + (sum%10);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int tmp = N;
  while(true) {
    tmp = func(tmp);
    ans++;

    if(tmp == N) {
      cout << ans;
      return 0;
    }
  }
}