#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[52][52];
bool visited[52][52];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M, N, K;
queue<pair<int, int> > Q;

void bfs(int y, int x) {
    visited[y][x] = true;
    Q.push({y, x});
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx] == true || board[ny][nx] == 0) continue;
            
            visited[ny][nx] = true;
            Q.push({ny, nx});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        cin >> M >> N >> K;
        
        while(K--) {
            int X, Y;
            cin >> X >> Y;
            board[Y][X] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(board[i][j] == 1 && visited[i][j] == false) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        
        for(int i = 0; i < N; ++i) {
            fill(board[i], board[i]+M, 0);
            fill(visited[i], visited[i]+M, false);
        }
    }
}
