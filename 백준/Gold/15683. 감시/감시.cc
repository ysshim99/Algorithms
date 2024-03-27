#include <bits/stdc++.h>
using namespace std;

int board[10][10]; // 최초 사무실의 배치
int marked[10][10]; // CCTV로 보는 화면
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctv; // CCTV의 위치 저장

int N, M;
int ans = INT_MAX;

bool OOB(int y, int x) {
  return (y < 0 || y >= N || x < 0 || x >= M);
}

// (x, y)에서 dir 방향으로 진행하면서 벽을 만날 때까지 모든 빈칸을 7로 바꿈
void markView(int y, int x, int dir) {
  dir %= 4;

  while(true) {
    y += dy[dir];
    x += dx[dir];

    if(OOB(y, x) || marked[y][x] == 6) return;
    if(marked[y][x] != 0) continue; // 해당 칸이 CCTV일 경우 넘어감
    marked[y][x] = 7;
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      cin >> board[i][j];

      if(board[i][j] != 0 && board[i][j] != 6)
        cctv.push_back({i, j});
    }
  }

  // 1 << (2*cctv.size()) == 4의 cctv.size()승을 의미
  // bitmask를 4진법으로 바꿨을 때 각 자릿수를 CCTV의 방향으로 생각
  for(int bitmask = 0; bitmask < (1 << (2*cctv.size())); ++bitmask) {
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j)
        marked[i][j] = board[i][j];
    
    int tmp = bitmask;
    for(int i = 0; i < cctv.size(); ++i) {
      int dir = tmp % 4;
      tmp /= 4;

      int x, y;
      tie(y, x) = cctv[i];

      if(board[y][x] == 1) markView(y, x, dir);
      if(board[y][x] == 2) {
        markView(y, x, dir);
        markView(y, x, dir+2);
      }
      if(board[y][x] == 3) {
        markView(y, x, dir);
        markView(y, x, dir+1);
      }
      if(board[y][x] == 4) {
        markView(y, x, dir);
        markView(y, x, dir+1);
        markView(y, x, dir+2);
      }
      if(board[y][x] == 5) {
        markView(y, x, dir);
        markView(y, x, dir+1);
        markView(y, x, dir+2);
        markView(y, x, dir+3);
      }
    }

    int cnt = 0;
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < M; ++j)
        cnt += (marked[i][j] == 0);
    
    ans = min(ans, cnt);
  }

  cout << ans;
}