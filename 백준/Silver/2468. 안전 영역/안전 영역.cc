#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[102][102];
bool visited[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > Q;

int N, maxLevel; // N: 한 변의 길이, maxLevel: 최대 높이
vector<int> v; // 나눠진 구역 개수 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
            maxLevel = max(maxLevel, board[i][j]);
        }
    }
    
    int level = 0;
    while(level <= maxLevel) {
        for(int i = 0; i < N; ++i) fill(visited[i], visited[i]+N, false);
        Q = {};
        int cnt = 0;
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(board[i][j] > level && visited[i][j] == false) {
                    cnt++;
                    visited[i][j] = true;
                    Q.push({i, j});

					while(!Q.empty()) {
						auto cur = Q.front(); Q.pop();

						for(int dir = 0; dir < 4; ++dir) {
							int ny = cur.Y + dy[dir];
							int nx = cur.X + dx[dir];

							if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
							if(board[ny][nx] <= level || visited[ny][nx] == true) continue;

							visited[ny][nx] = true;
							Q.push({ny, nx});
						}
					}
                }
            }
        }
		v.push_back(cnt);
		level++;
    }
    
    cout << *max_element(v.begin(), v.end());
}