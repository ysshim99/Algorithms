#include <bits/stdc++.h>
using namespace std;

int N;

long long factorial(int n) {
  if(n <= 1) return 1;
  return n * factorial(n-1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  cout << factorial(N);
}