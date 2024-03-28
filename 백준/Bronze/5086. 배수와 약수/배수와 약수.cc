#include <bits/stdc++.h>
using namespace std;

int num1, num2;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true) {
    cin >> num1 >> num2;
    if(num1 == 0 && num2 == 0) return 0;

    if(num2 % num1 == 0) {
      cout << "factor\n";
      continue;
    }
    if(num1 % num2 == 0) {
      cout << "multiple\n";
      continue;
    }
    cout << "neither\n";
  }
}