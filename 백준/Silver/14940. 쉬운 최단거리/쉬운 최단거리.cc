#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1005][1005];
int dist[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int n, m;

bool OOB(int x, int y) {
  return (x < 0 || x >= n || y < 0 || y >= m);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  
  // initialization
  for (int i = 0; i < n; ++i) fill(dist[i], dist[i]+m, -1);
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> board[i][j];
      
      // 역으로 목표 지점에서 탐색 시작
      if (board[i][j] == 2) {
        dist[i][j] = 0;
        q.push({i, j});
      }
      
      // 원래 갈 수 없는 땅
      if (board[i][j] == 0) {
        dist[i][j] = 0;
      }
    }
  }
  
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    
    for (int dir = 0; dir < 4; ++dir) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      
      if (OOB(nx, ny) || dist[nx][ny] != -1) continue;
      if (board[nx][ny] == 0) continue;
      
      dist[nx][ny] = dist[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
}