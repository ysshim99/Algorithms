#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;

// mCn
long long combination(int m, int n) {
  long long result = 1;
  
  int r = 1;
  for(int i = m; i > m-n; --i) {
    result *= i;
    result /= r++;
  }
  
  return result;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  
  while(T--) {
    cin >> N >> M;
    
    cout << combination(M, N) << '\n';
  }
}