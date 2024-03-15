#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

string board[1002];
int dist1[1002][1002]; //불에 대한 bfs
int dist2[1002][1002]; //상근이에 대한 bfs
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q1;
queue<pair<int, int>> Q2;

int w, h; //board[h][w] 꼴

void bfs1() {
    while(!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(board[ny][nx] == '#' || dist1[ny][nx] >= 0) continue;
            
            dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
            Q1.push({ny, nx});
        }
    }
}

void bfs2() {
    while(!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) {
                cout << dist2[cur.Y][cur.X] + 1 << '\n';
                return;
            }
            
            if(board[ny][nx] == '#' || dist2[ny][nx] >= 0) continue;
            if(dist1[ny][nx] >= 0 && dist1[ny][nx] <= dist2[cur.Y][cur.X] + 1) continue;
            
            dist2[ny][nx] = dist2[cur.Y][cur.X] + 1;
            Q2.push({ny, nx});
        }
    }
    
    cout << "IMPOSSIBLE\n";
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> w >> h;
        
        // bfs를 위한 initialization
        for(int i = 0; i < h; ++i) {
            cin >> board[i];
            fill(dist1[i], dist1[i]+w, -1);
            fill(dist2[i], dist2[i]+w, -1);
        }
        Q1 = {}; Q2 = {};
        
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(board[i][j] == '*') {
                    dist1[i][j] = 0;
                    Q1.push({i, j});
                }
                if(board[i][j] == '@') {
                    dist2[i][j] = 0;
                    Q2.push({i, j});
                }
            }
        }
        
        bfs1(); // 불에 대한 bfs
        bfs2(); // 상근이에 대한 bfs
    }
}
