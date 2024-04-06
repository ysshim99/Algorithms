#include <bits/stdc++.h>
using namespace std;

int board[22][22];
int dice[7];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int N, M, K;
int x, y;

int idx[5][4] = {
  {},
  {1, 4, 6, 3}, // 동쪽
  {1, 3, 6, 4}, // 서쪽
  {1, 5, 6, 2}, // 북쪽
  {1, 2, 6, 5}  // 남쪽
};

bool OOB(int x, int y) {
  return (x < 0 || x >= N || y < 0 || y >= M);
}

void rollDice(int dir) {
  int tmp[7];
  for(int i = 1; i < 7; ++i) tmp[i] = dice[i];
  
  for(int i = 0; i < 4; ++i) {
    tmp[idx[dir][i]] = dice[idx[dir][(i+1)%4]];
  }
  
  for(int i = 1; i < 7; ++i) dice[i] = tmp[i];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M >> x >> y >> K;
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      cin >> board[i][j];
    }
  }

  while(K--){
    int dir;
    cin >> dir;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(OOB(nx, ny)) continue;
    
    rollDice(dir);
    
    // 주사위, 바닥면에 적힌 수 update
    if(board[nx][ny] == 0) {
      board[nx][ny] = dice[6];
    }
    else {
      dice[6] = board[nx][ny];
      board[nx][ny] = 0;
    }
    
    // 주사위 상단 값 출력
    cout << dice[1] << '\n';
    
    // 주사위의 현재 좌표 update
    x = nx; y = ny; 
  }
}