#include <bits/stdc++.h>
using namespace std;

int selected[10];
bool used[10];

int N, M;

void func(int remain) {
  if(remain == 0) {
    for(int i = 0; i < M; ++i) {
      cout << selected[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; ++i) {
    if(!used[i]) {
      selected[M-remain] = i;
      used[i] = true;
      func(remain-1);
      used[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  func(M);
}