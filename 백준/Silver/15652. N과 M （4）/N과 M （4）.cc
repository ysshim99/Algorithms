#include <bits/stdc++.h>
using namespace std;

int selected[10];

int N, M;

// start ~ N 중에서 remain개 선택
void func(int start, int remain) {
  if(remain == 0) {
    for(int i = 0; i < M; ++i) {
      cout << selected[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = start; i <= N; ++i) {
    selected[M-remain] = i;
    func(i, remain-1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  func(1, M);
}