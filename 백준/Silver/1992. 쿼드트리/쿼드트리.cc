#include <bits/stdc++.h>
using namespace std;

int board[66][66];

int N;

bool check(int y, int x, int n) {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(board[y][x] != board[y+i][x+j]) return false;
    }
  }
  return true;
}

void func(int y, int x, int n) {
  if(check(y, x, n)) {
    cout << board[y][x];
    return;
  }

  cout << '(';
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < 2; ++j) {
      func(y + i*n/2, x + j*n/2, n/2);
    }
  }
  cout << ')';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i) {
    string input;
    cin >> input;

    for(int j = 0; j < N; ++j) {
      board[i][j] = input[j] - '0';
    }
  }

  func(0, 0, N);
}