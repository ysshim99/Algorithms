#include <bits/stdc++.h>
using namespace std;

map<long long, long long> F;

long long n;
const int mod = 1000000007;

long long fibo(long long n) {
  if(n <= 2) return 1;
  if(F.count(n)) return F[n];
  
  if(n % 2 == 0) 
    F[n] = (fibo(n/2) * (fibo(n/2+1) + fibo(n/2-1)) % mod) % mod;
  else 
    F[n] = ((fibo(n/2+1) * fibo(n/2+1)) % mod + (fibo(n/2) * fibo(n/2)) % mod) % mod;
  
  return F[n];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  
  cout << fibo(n);
}