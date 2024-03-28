#include <bits/stdc++.h>
using namespace std;

int angle1, angle2, angle3;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> angle1 >> angle2 >> angle3;

  if(angle1 + angle2 + angle3 == 180) {
    if(angle1 == angle2 || angle2 == angle3 || angle3 == angle1) {
      if(angle1 == angle2 && angle2 == angle3) cout << "Equilateral";
      else cout << "Isosceles";
    }
    else cout << "Scalene";
  }
  else cout << "Error";
}