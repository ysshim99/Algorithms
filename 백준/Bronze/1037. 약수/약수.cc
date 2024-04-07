#include <bits/stdc++.h>
using namespace std;

int n;
int divisors[52];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  
  for(int i = 0; i < n; ++i) cin >> divisors[i];
  sort(divisors, divisors+n);
  
  int N = divisors[0] * divisors[n-1];
  cout << N;
}