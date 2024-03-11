#include <bits/stdc++.h>
using namespace std;

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