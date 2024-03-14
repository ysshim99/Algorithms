#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

int board[52][52];
bool vis[52][52];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int m, n, k;
queue <pair<int, int >> q;

void bfs(int y, int x) {
    vis[y][x] = true;
    q.push({y, x});
    
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(vis[ny][nx] || board[ny][nx] != 1) continue;
            
            vis[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
    
  int t;
  cin >> t;
    
  while (t--) {
    cin >> m >> n >> k;
    int x, y;
      
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      board[y][x] = 1;
    }
      
    int res = 0; //지렁이 개수
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 1 && !vis[i][j]) {
          bfs(i, j);
          res++;
        }
      }
    }
      
    cout << res << "\n";
    for(int i = 0; i < n; i++){
      fill(board[i], board[i]+m, 0);
      fill(vis[i], vis[i]+m, false);
    }
  }
}