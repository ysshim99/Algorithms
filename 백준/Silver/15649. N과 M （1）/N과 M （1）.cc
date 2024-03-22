#include <bits/stdc++.h>
using namespace std;

int selected[10];
bool used[10];

int N, M;

// 현재까지 cnt개 수 선택
void func(int cnt) {
  if(cnt == M) {
    for(int i = 0; i < M; ++i) cout << selected[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; ++i) {
    if(!used[i]) {
      selected[cnt] = i;
      used[i] = true;
      func(cnt+1);
      used[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  func(0);
}
