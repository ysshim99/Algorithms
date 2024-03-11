#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.X(Y) 로 사용
#define X first
#define Y second

/*
익은 토마토(board = 1)는 queue에 push하여 해당 점부터 BFS를 수행한다.
익지 않은 토마토(board = 0)는 dist = -1로 한다.

!Q.empty일 때까지
    해당 위치에서 주변 위치를 조사한다.
    dist >= 0인 위치는 이미 조사했거나, 토마토가 없는 위치이므로 무시한다.
    주변 위치에 대하여 dist + 1을 하고, 
    queue에 push한다.
    
모든 점에 대해서
    dist = -1인 위치가 있는지 조사한다.
    만약 있다면, 익지 않은 토마토(board = 0)가 있는 것이므로 -1을 출력한다.
    dist의 최대값을 출력한다.
*/

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M, N;
    cin >> M >> N;
    
    queue<pair<int, int> > Q;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
            
            if(board[i][j] == 1) Q.push({i, j});
            if(board[i][j] == 0) dist[i][j] = -1;
        }
    }
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] >= 0) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    
    int days = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            
            days = max(days, dist[i][j]);
        }
    }
    
    cout << days;
}