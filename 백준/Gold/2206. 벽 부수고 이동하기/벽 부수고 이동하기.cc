#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

char board[1002][1002];
int dist[1002][1002][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<tuple<int, int, int> > Q;

int N, M;
int x, y, broken;

int bfs() {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      dist[i][j][0] = dist[i][j][1] = -1;
  dist[0][0][0] = dist[0][0][1] = 1;
  Q.push({0,0,0});
    
  while (!Q.empty()) {
    tie(y, x, broken) = Q.front(); Q.pop();
      
    if(y == N-1 && x == M-1) return dist[y][x][broken];
      
    int nextdist = dist[y][x][broken] + 1;
    for (int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
        
      if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;      
      if (board[ny][nx] == '0' && dist[ny][nx][broken] == -1) {
        dist[ny][nx][broken] = nextdist;
        Q.push({ny, nx, broken});
      }      
      // (ny, nx)를 부수는 경우
      if (!broken && board[ny][nx] == '1' && dist[ny][nx][1] == -1) {
        dist[ny][nx][1] = nextdist;
        Q.push({ny, nx, 1});
      }      
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> board[i][j];
  cout << bfs();
  return 0;
}