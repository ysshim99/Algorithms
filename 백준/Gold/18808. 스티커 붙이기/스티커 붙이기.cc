#include <bits/stdc++.h>
using namespace std;

int board[42][42];
int sticker[12][12];

int N, M, K; // board[N][M]
int R, C;    // sticker[R][C]
int ans;

// board[y][x]에 sticker[0][0]을 붙일 수 있는지 확인하는 함수
bool canPaste(int y, int x) {
  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      if(board[y+i][x+j] == 1 && sticker[i][j] == 1) return false;
    }
  }
  
  return true;
}

// board[y][x]에 sticker[0][0]을 붙이는 함수
void paste(int y, int x) {
  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      if(sticker[i][j] == 1) board[y+i][x+j] = 1;
    }
  }
}

// sticker를 붙일 수 있는지 확인하고 붙일 수 있다면 sticker를 붙임
bool tryPaste() {
  for(int y = 0; y <= N-R; ++y) {
    for(int x = 0; x <= M-C; ++x) {
      if(canPaste(y, x)) {
        paste(y, x);
        return true;
      }
    }
  }
  
  return false;
}

// sticker를 시계방향으로 90도 회전시키는 함수
void rotate() {
  int tmp[12][12];
  
  for(int i = 0; i < R; ++i) {
    for(int j = 0; j < C; ++j) {
      tmp[i][j] = sticker[i][j];
    }
  }
  
  for(int i = 0; i < C; ++i) {
    for(int j = 0; j < R; ++j) {
      sticker[i][j] = tmp[R-1-j][i];
    }
  }
  
  swap(R, C);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M >> K;
  
  while(K--) {
    cin >> R >> C;
    
    // sticker 정보 입력 받기
    for(int i = 0; i < R; ++i) {
      for(int j = 0; j < C; ++j) {
        cin >> sticker[i][j];
      }
    }
    
    for(int rot = 0; rot < 4; ++rot) {
      bool isPasted = tryPaste();
      if(isPasted) break;
      rotate();
    }
  }
  
  // 스티커가 붙은 칸의 수 세기
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      ans += board[i][j];
    }
  }
  
  cout << ans;
}