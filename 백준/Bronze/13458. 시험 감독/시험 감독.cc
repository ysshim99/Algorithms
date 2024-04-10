#include <bits/stdc++.h>
using namespace std;

int A[1000002];

int N, B, C;
long long supervisor;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  
  cin >> B >> C;
  
  for(int i = 0; i < N; ++i) {
    supervisor += 1; // 총감독관
    
    if(A[i] - B < 0) continue;
    supervisor += (A[i] - B)/C; // 부감독관
    if((A[i] - B) % C != 0) supervisor += 1;
  }
  
  cout << supervisor;
}