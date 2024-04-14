#include <bits/stdc++.h>
using namespace std;

int A[1000002], B[1000002], C[2000004];

int N, M;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < M; ++i) cin >> B[i];
  
  int idxA = 0, idxB = 0;
  for (int i = 0; i < N+M; ++i) {
    if (idxA == N) C[i] = B[idxB++];
    else if (idxB == M) C[i] = A[idxA++];
    else if (A[idxA] <= B[idxB]) C[i] = A[idxA++];
    else C[i] = B[idxB++];
  }
  
  for (int i = 0; i < N+M; ++i) cout << C[i] << ' ';  
}