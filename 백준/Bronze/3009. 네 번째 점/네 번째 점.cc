#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];

int X, Y;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
    X ^= x[i];
    Y ^= y[i];
  }

  cout << X << ' ' << Y;
}