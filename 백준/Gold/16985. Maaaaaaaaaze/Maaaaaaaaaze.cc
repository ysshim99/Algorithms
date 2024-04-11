#include <bits/stdc++.h>
using namespace std;

int board[5][5][5];  // board[i][j][k]: i번째 board
int maze[5][5][5];
int dist[5][5][5];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int ans = 9999;

bool OOB(int x, int y, int z) {
  return (x < 0 || x >= 5 || y < 0 || y >= 5 || z < 0 || z >= 5);
}

// i번째 판을 시계 방향으로 90도 회전하고 쌓기
void rotate90CW(int i) {
  int tmp[5][5];
  for (int j = 0; j < 5; ++j) {
    for (int k = 0; k < 5; ++k) {
      tmp[j][k] = maze[i][j][k];
    }
  }

  for (int j = 0; j < 5; ++j) {
    for (int k = 0; k < 5; ++k) {
      maze[i][j][k] = tmp[5 - 1 - k][j];
    }
  }
}

int escapeMaze() {
  if (maze[0][0][0] == 0 || maze[4][4][4] == 0) return 9999;

  // initialization
  fill_n(&dist[0][0][0], 5*5*5, -1);

  queue<tuple<int, int, int>> q;
  dist[0][0][0] = 0;
  q.push({0, 0, 0});

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (int dir = 0; dir < 6; ++dir) {
      int x, y, z;
      tie(x, y, z) = cur;

      if (x == 4 && y == 4 && z == 4) return dist[4][4][4];

      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nz = z + dz[dir];

      if (OOB(nx, ny, nz)) continue;
      if (maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != -1) continue;

      dist[nx][ny][nz] = dist[x][y][z] + 1;
      q.push({nx, ny, nz});
    }
  }

  return 9999;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      for (int k = 0; k < 5; ++k)
        cin >> board[i][j][k];

  int mask[5] = {0, 1, 2, 3, 4};
  do {
    for (int bitmask = 0; bitmask < (1 << 2*5); ++bitmask) {
      int tmp = bitmask;
      for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
          for (int k = 0; k < 5; ++k) {
            maze[i][j][k] = board[mask[i]][j][k];
          }
        }

        int rot = tmp % 4;
        tmp /= 4;
        for (int j = 0; j < rot; ++j) rotate90CW(i);
      }

      ans = min(ans, escapeMaze());
    }
  } while (next_permutation(mask, mask+5));

  if (ans == 9999) ans = -1;
  cout << ans;
}