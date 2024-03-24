#include <bits/stdc++.h>
using namespace std;

int fibo[42] = {0, 1, };

int T, N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  
  fibo[-1] = 1;
  for(int i = 2; i <= 40; ++i)
   fibo[i] = fibo[i-1] + fibo[i-2];

  while(T--) {
    cin >> N;

    // 0이 출력되는 횟수는 직전에 1이 출력된 횟수와 동일
    cout << fibo[N-1] << ' ' << fibo[N] << '\n';
  }
}