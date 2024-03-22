#include <bits/stdc++.h>
using namespace std;

int selected[10];
int input[10];

int N, M;

// 현재까지 cnt개 수 선택
void func(int cnt) {
  if(cnt == M) {
    for(int i = 0; i < M; ++i) cout << input[selected[i]] << ' ';
    cout << '\n';
    return;
  }

  int start = 0;
  if(cnt != 0) start = selected[cnt-1];

  int prev = -1;
  for(int i = start; i < N; ++i) {
    if(prev != input[i]) {
      selected[cnt] = i;
      prev = input[i];
      func(cnt+1);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; ++i) cin >> input[i];
  sort(input, input+N);

  func(0);
}