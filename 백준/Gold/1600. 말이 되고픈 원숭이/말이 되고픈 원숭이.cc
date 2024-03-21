#include <bits/stdc++.h>
using namespace std;

int board[202][202];
int dist[202][202][32];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int kx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<tuple<int, int, int>> Q;

int K, W, H; // board[H][W]

bool OOB(int y, int x) {
  return y < 0 || y >= H || x < 0 || x >= W;
}

int bfs() {
  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    int y, x, cnt;
    tie(y, x, cnt) = cur;

    if(y == H-1 && x == W-1) return dist[y][x][cnt];

    // 말의 움직임
    if(cnt < K) {
      for(int dir = 0; dir < 8; ++dir) {
        int ny = y + ky[dir];
        int nx = x + kx[dir];

        if(OOB(ny, nx) || board[ny][nx] == 1 || dist[ny][nx][cnt+1] != -1) continue;

        dist[ny][nx][cnt+1] = dist[y][x][cnt] + 1;
        Q.push({ny, nx, cnt+1});
      }
    }

    // 인접한 영역으로 움직임
    for(int dir = 0; dir < 4; ++dir) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if(OOB(ny, nx) || board[ny][nx] == 1 || dist[ny][nx][cnt] != -1) continue;

      dist[ny][nx][cnt] = dist[y][x][cnt] + 1;
      Q.push({ny, nx, cnt});
    }
  }

  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> W >> H;

  // initialization
  for(int i = 0; i < H; ++i) {
    for(int j = 0; j < W; ++j) {
      cin >> board[i][j];
      fill(dist[i][j], dist[i][j]+K+1, -1);
    }
  }
  dist[0][0][0] = 0;
  Q.push({0, 0, 0});

  cout << bfs();
}