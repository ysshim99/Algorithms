#include <bits/stdc++.h>
using namespace std;

int T, A, B;
char c;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while(T--) {
    cin >> A >> c >> B;
    cout << A + B << '\n';
  }
}