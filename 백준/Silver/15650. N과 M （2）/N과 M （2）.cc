#include <bits/stdc++.h>
using namespace std;

int selected[10];
// 이 문제는 오름차순으로 선택하므로 따로 used 배열을 선언하지 않아도 됨.

int N, M;

// start ~ N까지 remain개 골라야 함
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
    func(i+1, remain-1);
  }
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  func(1, M);
}