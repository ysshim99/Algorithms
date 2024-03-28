#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  int cnt = 0; // 현재까지 파악한 약수의 개수
  for(int i = 1; i <= N; ++i) {
    if(N % i == 0) cnt++;

    if(cnt == K) {
      cout << i;
      return 0;
    }
  }

  cout << 0;
}