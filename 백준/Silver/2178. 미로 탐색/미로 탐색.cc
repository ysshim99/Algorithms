#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.X(Y) 로 사용
#define X first
#define Y second

/*
시작점인 (0, 0)을 제일 먼저 queue에 push
이후 BFS 수행
queue가 비어있기 전까지 계속 수행
    queue에서 원소를 하나 pop
    원소의 주변 값을 전부 조사한다.
        범위 밖 or board != 1 or dist >= 0이면 무시한다.
        dist + 1

최종 답은 dist + 1 해야 한다.
*/

string board[100];
int dist[100][100] = {-1, };
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i)
        cin >> board[i];
    
    for(int i = 0; i < N; ++i) fill(dist[i], dist[i]+M, -1);
    
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    dist[0][0] = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
            
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    
    cout << dist[N-1][M-1] + 1;
}