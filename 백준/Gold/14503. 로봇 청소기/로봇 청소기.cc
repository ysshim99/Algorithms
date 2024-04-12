#include <bits/stdc++.h>
using namespace std;

int board[52][52]; // 청소 안 함: 0, 벽: 1, 청소 함: 2
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M; // board[N][M]
int x, y, dir;
bool isNotCleaned;
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  cin >> x >> y >> dir;
  
  for (int i = 0; i < N; ++i) 
    for (int j = 0; j < M; ++j)
      cin >> board[i][j];
  
  while (true) {
    // 현재 칸이 아직 청소되지 않은 경우
    if (board[x][y] == 0) {
      board[x][y] =2;
      ans++;
    }
    
    isNotCleaned = false;
    for (int i = 0; i < 4; ++i) {
      dir = (dir + 3) % 4;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      
      // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있다면
      if (board[nx][ny] != 0) continue;
      x = nx; y = ny;
      isNotCleaned = true;
      break;
    }
    // 1번으로 돌아가기
    if (isNotCleaned) continue;
    
    // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없다면
    int nx = x - dx[dir];
    int ny = y - dy[dir];
    
    // 바라보는 방향의 뒤쪽 칸이 벽이라면
    if (board[nx][ny] == 1) break;
    x = nx; y = ny;
  }
  
  cout << ans;
}