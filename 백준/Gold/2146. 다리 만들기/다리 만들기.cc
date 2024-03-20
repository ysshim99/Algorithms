#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[102][102];
bool visited[102][102];
int dist[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;

bool OOB(int y, int x) {
  return y < 0 || y >= N || x < 0 || x >= N;
}

void island() {
  int idx = 1;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(board[i][j] == 0 || visited[i][j]) continue;

      queue<pair<int, int>> Q;
      visited[i][j] = true;
      Q.push({i, j});

      while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        board[cur.Y][cur.X] = idx;

        for(int dir = 0; dir < 4; ++dir) {
          int ny = cur.Y + dy[dir];
          int nx = cur.X + dx[dir];

          if(OOB(ny, nx) || board[ny][nx] == 0 || visited[ny][nx]) continue;

          visited[ny][nx] = true;
          Q.push({ny, nx});
        }
      }
      idx++;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  // initialization
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < N; ++i) {
    fill(dist[i], dist[i]+N, -1);
  }

  island();

  queue<pair<int, int>> Q;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(board[i][j] != 0) {
        dist[i][j] = 0;
        Q.push({i, j});
      }
    }
  }

  int ans = INT_MAX;

  while(!Q.empty()) {
    auto cur = Q.front(); Q.pop();

    for(int dir = 0; dir < 4; ++dir) {
      int ny = cur.Y + dy[dir];
      int nx = cur.X + dx[dir];

      // OOB 혹은 인접한 곳이 같은 섬이라면
      if(OOB(ny, nx) || board[ny][nx] == board[cur.Y][cur.X]) continue;
      
      if(board[ny][nx] != 0) { // 인접한 곳이 다른 섬이라면
        ans = min(ans, dist[ny][nx] + dist[cur.Y][cur.X]);
      }
      else { // 바다라면
        board[ny][nx] = board[cur.Y][cur.X];
        dist[ny][nx] = dist[cur.Y][cur.X] + 1;
        Q.push({ny, nx});
      }
    }
  }

  cout << ans;
}