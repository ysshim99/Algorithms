#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

char board[12][6];
char board2[6][12];  // board를 시계 방향으로 90도 회전시킨 후, 왼쪽으로 미는 작업을 수행
bool visited[14][8];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isPuyo; // 뿌요가 터지면 true
int ans;

bool OOB(int y, int x) {
  return (y < 0 || y >= 12 || x < 0 || x >= 6);
}

void BFS(int y, int x) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> v; // 터질 뿌요의 위치 저장
  
  visited[y][x] = true;
  q.push({y, x}); v.push_back({y, x});
  
  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    
    for(int dir = 0; dir < 4; ++dir) {
      int ny = cur.Y + dy[dir];
      int nx = cur.X + dx[dir];
      
      if(OOB(ny, nx) || visited[ny][nx]) continue;
      if(board[ny][nx] == '.' || board[ny][nx] != board[cur.Y][cur.X]) continue;
      
      visited[ny][nx] = true;
      q.push({ny, nx}); v.push_back({ny, nx});
    }
  }
  
  if(v.size() < 4) return;
  
  // 같은 색의 뿌요가 4개 이상 모였다면
  isPuyo = true;
  for(auto cur : v) board[cur.Y][cur.X] = '.';
}

// 뿌요들을 아래로 떨어뜨리는 작업
void drop() {
  // 왼쪽으로 밀기 위해 시계 방향으로 90도 회전
  for(int i = 0; i < 6; ++i) {
    for(int j = 0; j < 12; ++j) {
      board2[i][j] = board[12-1-j][i];
    }
  }
  
  for(int i = 0; i < 6; ++i) {
    char tmp[12];
    fill(tmp, tmp+12, '.');
    int idx = 0;
    
    for(int j = 0; j < 12; ++j) {
      if(board2[i][j] == '.') continue;
      tmp[idx++] = board2[i][j];
    }
    
    for(int j = 0; j < 12; ++j) {
      board2[i][j] = tmp[j];
    }
  }
  
  // 원래대로 돌아가기 위해 시계 반대 방향으로 90도 회전
  for(int i = 0; i < 12; ++i) {
    for(int j = 0; j < 6; ++j) {
      board[i][j] = board2[j][12-1-i];
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < 12; ++i) {
    for(int j = 0; j < 6; ++j) {
      cin >> board[i][j];
    }
  }
  
  while(true) {
    // initialization
    isPuyo = false;
    
    for(int i = 0; i < 12; ++i) {
      for(int j = 0; j < 6; ++j) {
        visited[i][j] = false;
      }
    }
    
    // BFS 수행
    for(int i = 0; i < 12; ++i) {
      for(int j = 0; j < 6; ++j) {
        if(board[i][j] == '.' || visited[i][j]) continue;
        BFS(i, j);
      }
    }
    
    // 뿌요가 터졌다면
    if(!isPuyo) break;
    ans++;
    drop();
  }
  
  cout << ans;
}