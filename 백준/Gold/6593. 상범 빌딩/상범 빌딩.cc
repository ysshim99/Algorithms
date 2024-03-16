#include <bits/stdc++.h>
using namespace std;

char board[32][32][32];
int dist[32][32][32];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
queue<tuple<int, int, int> > Q;

int L, R, C; // L(층수), R(행), C(열) board[L][R][C]
bool escape; // true(탈출 성공), false(탈출 실패)
int curZ, curY, curX; // tuple의 first, second, third

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true) {
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) return 0;
        
        // initialization
        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                fill(dist[i][j], dist[i][j]+C, -1);
            }
        }
        Q = {}; escape = false;
        
        for(int i = 0; i < L; ++i) {
            for(int j = 0; j < R; ++j) {
                for(int k = 0; k < C; ++k) {
                    cin >> board[i][j][k];
                    
                    if(board[i][j][k] == 'S') {
                        dist[i][j][k] = 0;
                        Q.push({i, j, k});
                    }
                }
            }
        }
        
        while(!Q.empty() && !escape) {
            auto cur = Q.front(); Q.pop();
            tie(curZ, curY, curX) = cur;
            
            for(int dir = 0; dir < 6; ++dir) {
                int nz = curZ + dz[dir];
                int ny = curY + dy[dir];
                int nx = curX + dx[dir];
                
                if(board[nz][ny][nx] == 'E') {
                    cout << "Escaped in " << dist[curZ][curY][curX] + 1 <<  " minute(s).\n";
                    escape = true;
                    break;
                }
                if(nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if(board[nz][ny][nx] == '#' || dist[nz][ny][nx] >= 0) continue;
                
                dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
                Q.push({nz, ny, nx});
            }
        }
        
        if(!escape) cout << "Trapped!\n";
    }
}