#include <bits/stdc++.h>
using namespace std;

bool used1[40];
bool used2[40];
bool used3[40];

int cnt = 0;
int N;

// 'row'번째 row에 queen을 놓을 차례
// 현재 체스판에 'row'개 queen이 있다.
void func(int row) {
  if(row == N) {
    cnt++;
    return;
  }

  // (row, col)에 queen을 놓는다.
  for(int col = 0; col < N; ++col) {
    if(used1[col] || used2[col+row] || used3[row-col+N-1]) continue;
    used1[col] = true;
    used2[col+row] = true;
    used3[row-col+N-1] = true;
    func(row+1);
    used1[col] = false;
    used2[col+row] = false;
    used3[row-col+N-1] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  func(0);
  cout << cnt;
}