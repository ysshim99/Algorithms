#include <bits/stdc++.h>
using namespace std;

int A, B;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;

  cout << A / B << '.';
  A %= B;

  for(int i = 0; i < 1000; ++i) {
    if(A == 0) return 0;
    
    A *= 10;
    cout << A / B;
    A %= B;
  }
}