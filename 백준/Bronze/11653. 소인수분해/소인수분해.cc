#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 2; i <= N; ++i) {
    while(true) {
      if(N % i == 0) {
        cout << i << '\n';
        N /= i;
      }
      else break;
    }
  }
}