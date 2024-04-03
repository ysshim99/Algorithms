#include <bits/stdc++.h>
using namespace std;

vector<deque<char>> gear(5); // gear[1] ~ gear[4]까지 채워짐
int dirs[5];                 // dirs[1] ~ dirs[4]까지 채워짐

int K, num, dir;

void setRotation(int num, int dir) {
  // initialization
  fill(dirs, dirs+5, 0);
  
  dirs[num] = dir;
  
  // 왼쪽으로 전파
  int idx = num;
  while(idx > 1 && gear[idx][6] != gear[idx-1][2]) {
    dirs[idx-1] = -dirs[idx];
    idx--;
  }
  
  // 오른쪽으로 전파
  idx = num;
  while(idx < 4 && gear[idx][2] != gear[idx+1][6]) {
    dirs[idx+1] = -dirs[idx];
    idx++;
  }
}

void rotateGear() {
  for(int i = 1; i <= 4; ++i) {
    if(dirs[i] == 0) continue;
    if(dirs[i] == 1) { // 시계 방향
      char tmp = gear[i].back();
      gear[i].pop_back();
      gear[i].push_front(tmp);
    }
    if(dirs[i] == -1) { // 반시계 방향
      char tmp = gear[i].front();
      gear[i].pop_front();
      gear[i].push_back(tmp);
    }
  }
}

void printScore() {
  int score = 0;
  for(int i = 1; i <= 4; ++i) {
    if(gear[i][0] == '1') score += (1 << i-1);
  }
  
  cout << score;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 1; i <= 4; ++i) {
    for(int j = 0; j < 8; ++j) {
      char c;
      cin >> c;
      
      gear[i].push_back(c);
    }
  }
  
  cin >> K;
  
  while(K--) {
    cin >> num >> dir;
    
    setRotation(num, dir);
    rotateGear();
  }
  
  printScore();
}