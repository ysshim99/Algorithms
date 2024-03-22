#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int cnt[3]; // -1, 0, 1로만 채워진 종이 개수

int N;

// 해당 종이가 같은 숫자로만 채워졌는지 검사
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
    cnt[board[y][x] + 1]++;
    return;
  }

  for(int i = 0; i < 3; ++i) {
    for(int j = 0; j < 3; ++j) {
      func(y + i*n/3, x + j*n/3, n/3);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> board[i][j];
    }
  }

  func(0, 0, N);

  for(auto d : cnt) cout << d << '\n';
}