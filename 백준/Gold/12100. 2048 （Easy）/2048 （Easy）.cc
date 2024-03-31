#include <bits/stdc++.h>
using namespace std;

int board[22][22];  // 초기 게임판 상태
int tilted[22][22]; // 기울일 게임판 상태 = 초기 게임판의 복사본

int N;
int ans = INT_MIN;

// 게임판을 시계 방향으로 90도 회전
void rotate() {
  int tmp[22][22];
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      tmp[i][j] = tilted[i][j];
    }
  }
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      tilted[i][j] = tmp[N-1-j][i];
    }
  }
}

// dir 방향으로 게임판 기울이기
void tiltBoard(int dir) {
  while(dir--) rotate();
    
  for(int i = 0; i < N; ++i) {
    int arr[22] = {};
    int idx = 0;
    
    for(int j = 0; j < N; ++j) {
      if(tilted[i][j] == 0) continue;
      if(arr[idx] == 0) arr[idx] = tilted[i][j];
      else if(arr[idx] == tilted[i][j]) arr[idx++] *= 2;
      else arr[++idx] = tilted[i][j];
    }
    
    for(int j = 0; j < N; ++j) {
      tilted[i][j] = arr[j];
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  // 게임판의 초기 상태
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> board[i][j];
    }
  }
  
  // 4개 방향으로 5번씩 기울이기
  for(int bitmask = 0; bitmask < (1 << 2*5); ++bitmask) {
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        tilted[i][j] = board[i][j];
      }
    }
    
    int tmp = bitmask;
    for(int i = 0; i < 5; ++i) {
      int dir = tmp % 4;
      tmp /= 4;
      
      tiltBoard(dir);
    }
    
    // 가장 큰 블록 계산하기
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        ans = max(ans, tilted[i][j]);
      }
    }
  }
  
  cout << ans;
}