#include <bits/stdc++.h>
using namespace std;

int N, B;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> B;

  string num;
  while(N > 0) {
    int remain = N % B;

    if(remain >= 10) num += remain-10+'A';
    else num += remain+'0';

    N /= B;
  }

  reverse(num.begin(), num.end());
  cout << num;
}