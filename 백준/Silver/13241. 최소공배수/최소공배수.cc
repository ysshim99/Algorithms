#include <bits/stdc++.h>
using namespace std;

long long A, B;

long long GCD(long long a, long long b) {
  if(b == 0) return a;
  return GCD(b, a%b);
}

long long LCM(long long a, long long b) {
  return a * b / GCD(a, b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;

  cout << LCM(A, B);
}