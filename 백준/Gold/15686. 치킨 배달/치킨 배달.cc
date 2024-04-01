#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int N, M; // board[N][N]
int ans = INT_MAX;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      cin >> board[i][j];
      if(board[i][j] == 1) house.push_back({i, j});
      if(board[i][j] == 2) chicken.push_back({i, j});
    }
  }
  
  // 0: M개, 1: chicken.size()-M개
  vector<bool> mask(chicken.size(), true);
  fill(mask.begin(), mask.begin()+M, false);
  
  do {
    int sum = 0; // 도시의 치킨 거리
    
    for(auto cur : house) {
      int dist = INT_MAX; // 각 집의 치킨 거리
      
      for(int i = 0; i < chicken.size(); ++i) {
        if(mask[i]) continue;
        dist = min(dist, abs(chicken[i].Y - cur.Y) + abs(chicken[i].X - cur.X));
      }
      sum += dist;
    }
    ans = min(ans, sum);
  } while(next_permutation(mask.begin(), mask.end()));
  
  cout << ans;
}