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

int M, N, K; // board[M][N], K개의 사각형
vector<int> arr; // 각 구역의 넓이 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> M >> N >> K;
    
    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i = y1; i < y2; ++i) {
            for(int j = x1; j < x2; ++j) {
                board[i][j] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == 1 || visited[i][j] == true) continue;
            cnt++;
            visited[i][j] = true;
            Q.push({i, j});
            
            int area = 0;
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                area++;
                
                for(int dir = 0; dir < 4; ++dir) {
                    int ny = cur.Y + dy[dir];
                    int nx = cur.X + dx[dir];
                    
                    if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
                    if(board[ny][nx] == 1 || visited[ny][nx] == true) continue;
                    
                    visited[ny][nx] = true;
                    Q.push({ny, nx});
                }
            }
            arr.push_back(area);
        }
    }
    sort(arr.begin(), arr.end());
    
    cout << cnt << '\n';
    for(auto area : arr) cout << area << ' ';
}