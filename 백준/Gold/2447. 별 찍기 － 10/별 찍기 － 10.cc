#include <bits/stdc++.h>
using namespace std;

char board[2300][2300];

int N;

void func(int y, int x, int n) {
  if(n == 1) {
    board[y][x] = '*';
    return;
  }

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      if(i == 1 && j == 1) continue;
      func(y + i*n/3, x + j*n/3, n/3);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i) {
    fill(board[i], board[i]+N, ' ');
  }

  func(0, 0, N);

  for(int i = 0; i < N; ++i) {
    cout << board[i] << '\n';
  }
}