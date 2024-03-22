#include <bits/stdc++.h>
using namespace std;

int selected[10];
bool used[10];
int input[10];

int N, M;

void func(int remain) {
  if(remain == 0) {
    for(int i = 0; i < M; ++i) cout << selected[i] << ' ';
    cout << '\n';
    return;
  }

  int prev = -1;
  for(int i = 0; i < N; ++i) {
    if(!used[i] && prev != input[i]) {
      selected[M-remain] = input[i];
      prev = input[i];
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

  for(int i = 0; i < N; ++i) {
    cin >> input[i];
  }
  sort(input, input+N);

  func(M);
}