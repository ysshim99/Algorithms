#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

string board[27];
bool visited[27][27];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int> > Q;

int N; // board[N][N]
vector<int> arr; // 각 단지의 집의 수

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == '0' || visited[i][j] == true) continue;
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
                    
                    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    if(board[ny][nx] == '0' || visited[ny][nx] == true) continue;
                    
                    visited[ny][nx] = true;
                    Q.push({ny, nx});
                }
            }
            arr.push_back(area);
        }
    }
    sort(arr.begin(), arr.end());
    
    cout << cnt << '\n';
    for(auto area : arr) cout << area << '\n';
}