#include <bits/stdc++.h>
using namespace std;

/*
익은 토마토(board = 1)는 queue에 push 하여 해당 점부터 BFS를 수행한다.
익지 않은 토마토(board = 0)는 dist = -1로 한다.

마지막에 답을 출력할 땐, 거리가 가장 먼 것을 찾는다.
단, 익지 않은 토마토(board = -1)가 있다면, -1을 출력한다.

주의해야 할 점은 인자를 받을 때 `높이, 세로, 가로` 순이라는 점이다.

tuple의 인자를 가져오는 방법은 두 가지가 있다. 
1. get 함수 이용하기
    x_i = get<i>(tuple)
2. tie 함수 이용하기
    tie(x, y, z) = tuple
*/

int board[102][102][102];
int dist[102][102][102];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, H;
    cin >> M >> N >> H;

    queue<tuple<int, int, int> > Q;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < M; ++k) {
                cin >> board[i][j][k];

                if(board[i][j][k] == 1) Q.push({i, j, k});
                if(board[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }

    while(!Q.empty()) {
        int z, y, x;
        tie(z, y, x) = Q.front();
        Q.pop();

        for(int dir = 0; dir < 6; ++dir) {
            int nz = z + dz[dir];
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(dist[nz][ny][nx] >= 0) continue;

            dist[nz][ny][nx] = dist[z][y][x] + 1;
            Q.push({nz, ny, nx});
        }
    }

    int days = 0;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < M; ++k) {
                if(dist[i][j][k] == -1) {
                    cout << -1;
                    return 0;
                }

                days = max(days, dist[i][j][k]);
            }
        }
    }

    cout << days;
}
