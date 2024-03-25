#include <bits/stdc++.h>
using namespace std;

int T, C;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while(T--) {
    cin >> C;
    
    int quarter = C / 25; C %= 25;
    int dime = C / 10; C %= 10;
    int nickel = C / 5; C %= 5;
    int penny = C;

    cout << quarter << ' ' << dime << ' ' << nickel << ' ' << penny << '\n';
  }
}