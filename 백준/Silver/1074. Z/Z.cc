#include <bits/stdc++.h>
using namespace std;

/*
func 함수는 2^n x 2^n 배열에서 (r, c)를 방문하는 순서를 반환하는 함수
base condition: n = 0일 때 -> 0

half = 2^(n-1)
(r, c)가 0번 사각형일 때 -> func(n-1, r, c)
(r, c)가 1번 사각형일 때 -> half*half + func(n-1, r, c-half)
(r, c)가 2번 사각형일 때 -> 2*half*half + func(n-1, r-half, c)
(r, c)가 3번 사각형일 때 -> 3*half*half + func(n-1, r-half, c-half)
*/

int N, r, c;

int func(int n, int r, int c) {
  if(n == 0) return 0;

  int half = 1<<(n-1);
  if(r < half && c < half) return func(n-1, r, c);
  if(r < half && c >= half) return half*half + func(n-1, r, c-half);
  if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
  return 3*half*half + func(n-1, r-half, c-half);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> r >> c;

  cout << func(N, r, c);
}