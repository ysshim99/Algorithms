#include <bits/stdc++.h>
using namespace std;

int T, N;
int cnt;

vector<bool> isPrime(1000002, true);

// 에라토스테네스의 체
void sieve() {
  isPrime[0] = isPrime[1] = false;
  
  for(int i = 2; i*i <= 1000000; ++i) {
    if(!isPrime[i]) continue;
    
    for(int j = i*i; j <= 1000000; j += i) {
      isPrime[j] = false;
    }
  }
}

int countGoldbachPartition(int N) {
  cnt = 0;
  
  for(int i = 2; i <= N/2; ++i) {
    if(isPrime[i] && isPrime[N-i]) {
      cnt++;
    }
  }
  
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  sieve();
  
  cin >> T;
  
  while(T--) {
    cin >> N;
    cout << countGoldbachPartition(N) << '\n';    
  }
}