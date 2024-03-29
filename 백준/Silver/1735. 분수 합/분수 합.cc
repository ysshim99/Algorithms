#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int GCD(int a, int b) {
  if(b == 0) return a;
  return GCD(b, a%b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c >> d;

  int gcd = GCD(a*d + b*c, b*d);
  cout << (a*d + b*c) / gcd << ' ' << (b*d) / gcd;
}