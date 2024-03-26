#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

string board[5];
bool mask[25];
bool visited[5][5];
bool selected[5][5]; // 소문난 칠공주 선택
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

bool OOB(int y, int x) {
  return (y < 0 || y >= 5 || x < 0 || x >= 5);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; ++i) cin >> board[i];
  fill(mask+7, mask+25, true);
  
  do {
    // initialization
    queue<pair<int, int>> q;
    for(int i = 0; i < 5; ++i) {
      fill(visited[i], visited[i]+5, false);
      fill(selected[i], selected[i]+5, false);
    }

    for(int i = 0; i < 25; ++i) {
      if(!mask[i]) {
        int y = i/5;
        int x = i%5;

        selected[y][x] = true;

        if(q.empty()) {
          visited[y][x] = true;
          q.push({y, x});
        }
      }
    }

    int cnt = 0; // cnt: 소문난 칠공주 중 이다솜파 학생 수
    int adj = 0; // adj: 인접한 학생 수
    while(!q.empty()) {
      auto cur = q.front(); q.pop();

      if(board[cur.Y][cur.X] == 'S') cnt++;
      adj++;

      for(int dir = 0; dir < 4; ++dir) {
        int ny = cur.Y + dy[dir];
        int nx = cur.X + dx[dir];

        if(OOB(ny, nx) || visited[ny][nx] || !selected[ny][nx]) continue;

        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }

    if(adj == 7 && cnt >= 4) ans++;
  } while(next_permutation(mask, mask+25));

  cout << ans;
}