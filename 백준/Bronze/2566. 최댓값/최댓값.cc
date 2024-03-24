#include <bits/stdc++.h>
using namespace std;

int board[9][9];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9; ++j)
      cin >> board[i][j];

  int max = -1; int maxRow = -1; int maxCol = -1;
  for(int i = 0; i < 9; ++i) {
    for(int j = 0; j < 9; ++j) {
      if(max < board[i][j]) {
        max = board[i][j];
        maxRow = i; maxCol = j;
      }
    }
  }

  cout << max << '\n';
  cout << maxRow+1 << ' ' << maxCol+1;
}