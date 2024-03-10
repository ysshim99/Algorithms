#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.X(Y) 로 사용
#define X first
#define Y second

/*
모든 점에 대해서
    board = 0 or visited = true이면 무시한다.
    아니라면, 새로운 그림이므로 num++
    visited = true and queue에 push
    이후, 그 점에 대해서 BFS 수행한다.

BFS 수행
queue가 비어있기 전까지 계속 수행
    queue에서 원소를 하나 pop 할 때마다 area++
    원소의 주변 값을 전부 조사한다.
        범위 밖 or visited = true이면 무시한다.
        visited = true and queue에 push

num : board에서 그림의 개수
area : 조사하는 그림의 넓이
maxArea : board에서 가장 넓은 그림의 넓이
*/

int board[500][500];
bool visited[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    
    int num = 0;
    int maxArea = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0 || visited[i][j]) continue;
            
            num++;
            
            queue<pair<int, int> > Q;
            Q.push({i, j});
            visited[i][j] = true;
            
            int area = 0;
            
            while(!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                area++;
                
                for(int dir = 0; dir < 4; ++dir) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] == 0 || visited[nx][ny]) continue;
                    
                    Q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
            
            maxArea = max(maxArea, area);
        }
    }
    
    cout << num << '\n' << maxArea;
}
