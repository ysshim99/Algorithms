#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;
  int sides[3] = {a, b, c};
  
  sort(sides, sides+3);

  if(sides[2] < sides[0] + sides[1]) cout << sides[0] + sides[1] + sides[2];
  else cout << 2*(sides[0] + sides[1]) - 1;
}