#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c >> d >> e >> f;

  int x = (c*e - b*f) / (a*e - b*d);
  int y = (c*d - a*f) / (b*d - a*e);

  cout << x << ' ' << y;
}