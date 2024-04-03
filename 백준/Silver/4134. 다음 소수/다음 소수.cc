#include <bits/stdc++.h>
using namespace std;

int T;
long long n;

bool isPrime(long long n) {
  if(n <= 1) return false;
  if(n == 2) return true;
  
  for(long long i = 2; i * i <= n; ++i)
    if(n % i == 0) return false;
  
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  
  while(T--) {
    cin >> n;
    while(!isPrime(n)) n++;
    
    cout << n << '\n';
  }
}