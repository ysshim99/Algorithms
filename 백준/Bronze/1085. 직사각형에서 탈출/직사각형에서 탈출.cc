#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y >> w >> h;

  int minX = min(abs(w-x), abs(x));
  int minY = min(abs(h-y), abs(y));
  cout << min(minX, minY);
}