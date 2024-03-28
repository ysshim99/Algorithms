#include <bits/stdc++.h>
using namespace std;

int M, N;

bool isPrime(int n) {
  if(n == 1) return false;
  
  for(int i = 2; i*i <= n; ++i)
    if(n % i == 0) return false;

  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;

  int sum = 0;
  vector<int> prime;

  for(int i = M; i <= N; ++i) {
    if(isPrime(i)) {
      sum += i;
      prime.push_back(i);
    }
  }

  if(prime.size() == 0) {
    cout << -1;
    return 0;
  }

  cout << sum << '\n' << prime[0];
}