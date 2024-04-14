#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool visited[502][502];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int sum, ans;

bool OOB(int x, int y) {
  return (x < 0 || x >= N || y < 0 || y >= M);
}

// 현재 cnt번째 정사각형 확인 중
void func(int x, int y, int cnt) { 
  if (cnt == 4) {
    ans = max(ans, sum);
    return;
  }
  
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if (OOB(nx, ny) || visited[nx][ny]) continue;
    
    sum += board[nx][ny];
    visited[nx][ny] = true;
    
    func(nx, ny, cnt+1);
    if (cnt == 2) // ㅗ 모양을 확인하기 위함
      func(x, y, cnt+1);
      
    sum -= board[nx][ny];
    visited[nx][ny] = false;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> board[i][j];
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      sum = board[i][j];
      visited[i][j] = true;
      func(i, j, 1);
      visited[i][j] = false;
    }
  }
  
  cout << ans;
}