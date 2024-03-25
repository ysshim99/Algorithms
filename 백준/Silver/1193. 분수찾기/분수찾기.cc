#include <bits/stdc++.h>
using namespace std;

int X;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> X;

  int n = 0;
  while(n*(n+1)/2 < X) n++;

  int d = X - n*(n-1)/2;
  
  if(n % 2 == 0) cout << d << '/' << n+1-d;
  else cout << n+1-d << '/' << d;
}