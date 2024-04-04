#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int n) {
  if(n == 1) return false;
  else if(n <= 3) return true;
  
  for(int i = 2; i * i <= n; ++i)
    if(n % i == 0) return false;
  
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while(true) {
    cin >> n;
    
    if(n == 0) return 0;
    
    int cnt = 0;
    for(int i = n+1; i <= 2*n; ++i) {
      if(isPrime(i)) cnt++;
    }
    
    cout << cnt << '\n';
  }
}