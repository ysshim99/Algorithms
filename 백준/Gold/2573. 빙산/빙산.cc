#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

int board[302][302];
bool visited[302][302];
int countZero[302][302];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;

int N, M; // board[N][M]
int year; // 최초부터 흐른 연(년)수
int cnt; // 분리된 빙하 수
bool isMelted; // 빙하가 다 녹았으면 true, 아니면 false

void melting() {
    // initialization
    for(int i = 0; i < N; ++i) {
        fill(countZero[i], countZero[i]+M, 0);
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(board[i][j] == 0) continue;

            for(int dir = 0; dir < 4; ++dir) {
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(board[ny][nx] > 0) continue;

                countZero[i][j]++;
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            board[i][j] = max(0, board[i][j] - countZero[i][j]);
        }
    }
}

int counting() {
    // initialization
    for(int i = 0; i < N; ++i) {
        fill(visited[i], visited[i]+M, 0);
    }
    Q = {}; 
    int cnt = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(board[i][j] > 0 && visited[i][j] == false) {
                visited[i][j] = true;
                cnt++;
                Q.push({i, j});

                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();

                    for(int dir = 0; dir < 4; ++dir) {
                        int ny = cur.Y + dy[dir];
                        int nx = cur.X + dx[dir];

                        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                        if(board[ny][nx] == 0 || visited[ny][nx] == true) continue;

                        visited[ny][nx] = true;
                        Q.push({ny, nx});
                    }
                }
            }
        }
    }

    // 빙하가 다 녹았는지 확인
    int area = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(board[i][j] > 0) area++;
        }
    }
    if(area == 0) isMelted = true;
    else isMelted = false;

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    // 빙하 녹이기
    while(true) {
        year++;
        melting();
        cnt = counting();

        if(isMelted || cnt >= 2) break;
    }

    if(isMelted) cout << 0;
    else cout << year;
}
