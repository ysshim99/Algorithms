#include <bits/stdc++.h>
using namespace std;

char board[3100][6200];

int N;

void func(int y, int x, int n) {
  if(n == 3) {
    board[y][x] = '*';
    board[y+1][x-1] = board[y+1][x+1] = '*';
    for(int i = -2; i <= 2; ++i) {
      board[y+2][x+i] = '*';
    }
    return;
  }

  func(y, x, n/2);
  func(y+n/2, x-n/2, n/2);
  func(y+n/2, x+n/2, n/2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i) {
    fill(board[i], board[i]+2*N, ' ');
  }

  func(0, N-1, N);

  for(int i = 0; i < N; ++i) {
    cout << board[i] << '\n';
  }
}