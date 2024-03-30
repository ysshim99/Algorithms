#include <bits/stdc++.h>
using namespace std;

int pos[100002];
int d[100002];

int N;

int GCD(int a, int b) {
  if(b == 0) return a;
  return GCD(b, a%b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for(int i = 0; i < N; ++i) cin >> pos[i];
  for(int i = 0; i < N-1; ++i) d[i] = pos[i+1] - pos[i];
  
  int gcd = d[0];
  for(int i = 0; i < N-1; ++i) gcd = GCD(gcd, d[i]);
  
  cout << (pos[N-1] - pos[0]) / gcd + 1 - N;
}