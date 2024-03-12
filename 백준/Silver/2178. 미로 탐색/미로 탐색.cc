#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X) 로 사용
#define Y first
#define X second

/*
시작점인 (0, 0)을 제일 먼저 queue에 push
이후 BFS 수행
queue가 비어있기 전까지 계속 수행
    queue에서 원소를 하나 pop
    원소의 주변 값을 전부 조사한다.
        범위 밖 or board != 1 or dist >= 0이면 무시한다.
        dist + 1

최종 답은 dist + 1 해야 한다.

dist : -1로 초기화하여 해당 원소를 방문했는지 여부도 같이 알 수 있다.
*/

string board[102];
int dist[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    queue<pair<int, int> > Q;
    Q.push({0, 0});
    dist[0][0] = 1;

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];

            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(board[ny][nx] == '0' || dist[ny][nx] > 0) continue;

            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            Q.push({ny, nx});
        }
    }

    cout << dist[N-1][M-1];
}