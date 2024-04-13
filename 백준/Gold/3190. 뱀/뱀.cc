#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];  // 1: 사과, 2: 뱀의 몸이 있는 곳
int dx[4] = {-1, 0, 1, 0}; // 0: 북, 1: 동, 2: 남, 3: 서
int dy[4] = {0, 1, 0, -1};

queue<pair<int ,char>> changeDir;
deque<pair<int, int>> snake;

int N, K, L;
int dir, gameTime;

bool OOB(int x, int y) {
  return (x < 0 || x >= N || y < 0 || y >= N);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  // 사과 위치 정보
  while (K--) {
    int x, y;
    cin >> x >> y;
    board[x-1][y-1] = 1;
  }

  cin >> L;

  // 뱀의 방향 변환 정보
  while (L--) {
    int x; char c;
    cin >> x >> c;
    changeDir.push({x, c});
  }

  // 뱀의 초기 위치
  dir = 1;
  snake.push_front({0, 0});

  while (true) {
    gameTime++;
    
    auto head = snake.front();
    int nx = head.X + dx[dir];
    int ny = head.Y + dy[dir];
    
    // 뱀의 머리 움직임
    board[head.X][head.Y] = 2;
    snake.push_front({nx, ny});

    // 벽이나 자기자신의 몸과 부딪히면
    if (OOB(nx, ny) || board[nx][ny] == 2) break;
    
    // 이동한 칸에 사과가 없다면
    if (board[nx][ny] != 1) {
      auto tail = snake.back();
      board[tail.X][tail.Y] = 0;
      snake.pop_back();
    }

    // 뱀의 방향 변환
    auto cur = changeDir.front();
    if (cur.X == gameTime) {
      if (cur.Y == 'L') dir = (dir + 3) % 4; // 반시계
      if (cur.Y == 'D') dir = (dir + 1) % 4; // 시계
      changeDir.pop();
    }
  }
  
  cout << gameTime;
}