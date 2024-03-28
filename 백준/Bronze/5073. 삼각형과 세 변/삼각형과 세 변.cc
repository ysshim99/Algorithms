#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true) {
    cin >> a >> b >> c;
    if(a == 0 && b == 0 && c == 0) return 0;

    int sides[3] = {a, b, c};
    sort(sides, sides+3);

    if(sides[2] >= sides[0] + sides[1]) cout << "Invalid\n";
    else if(a == b && b == c) cout << "Equilateral\n";
    else if(a == b || b == c || c == a) cout << "Isosceles\n";
    else cout << "Scalene\n";
  }
}