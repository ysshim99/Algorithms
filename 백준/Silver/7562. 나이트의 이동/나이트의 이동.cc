#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[302][302];
int dist[302][302];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
queue<pair<int, int> > Q;
pair<int, int> src, dst;

int T, l;

void bfs() {
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 8; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= l || nx < 0 || nx >= l) continue;
            if(dist[ny][nx] >= 0) continue;
            
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            Q.push({ny, nx});
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while(T--) {
        cin >> l;
        for(int i = 0; i < l; ++i) fill(dist[i], dist[i]+l, -1);
        
        cin >> src.Y >> src.X;
        dist[src.Y][src.X] = 0;
        Q.push(src);
        
        cin >> dst.Y >> dst.X;
        
        bfs();
        cout << dist[dst.Y][dst.X] << '\n';
    }
}