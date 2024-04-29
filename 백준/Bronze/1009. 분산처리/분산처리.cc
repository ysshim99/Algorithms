#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  
  while (T--) {
    cin >> a >> b;
    
    a %= 10;
    b = (b % 4) + 4;
    
    if (a == 0) cout << 10 << '\n';
    else {
      int tmp = 1;
      for (int i = 0; i < b; ++i) tmp = (tmp * a) % 10;
      cout << tmp << '\n';
    }
  }
}