#include <bits/stdc++.h>
using namespace std;

int T;
int A, B;

int GCD(int a, int b) {
  int gcd;
  for(int i = 1; i <= a; ++i)
    if(a % i == 0 && b % i == 0) gcd = i;

  return gcd;
}

int LCM(int a, int b) {
  return a * b / GCD(a, b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while(T--) {
    cin >> A >> B;
    cout << LCM(A, B) << '\n';
  }
}