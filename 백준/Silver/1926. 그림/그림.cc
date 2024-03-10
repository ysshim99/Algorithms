#include <bits/stdc++.h>
using namespace std;

// pair에서 first, second를 줄여서 쓰기 위해서 사용
#define X first
#define Y second

/*
각 칸이 BFS의 시작점이 될 수 있는지 확인 <=> board = 0 or visited = true면 다음 칸으로 넘어감.
그림 개수 + 1
해당 점을 visited = true & stack에 push
*/

int board[500][500];  // 그림: 1로 연결된 부분
bool visited[500][500]; // 방문 o: 1, 방문 x: 0
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    
    int maxArea = 0; // 가장 넓은 그림의 넓이
    int num = 0;     // 그림의 개수
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0 || visited[i][j]) continue;
            
            num++;
            queue<pair<int, int> > Q;
            visited[i][j] = true;
            Q.push({i, j});
            
            int area = 0;
            
            while(!Q.empty()) {
                area++;
                
                pair<int, int> cur = Q.front();
                Q.pop();
                
                for(int dir = 0; dir < 4; ++dir) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] != 1 || visited[nx][ny]) continue;
                    
                    visited[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            
            maxArea = max(maxArea, area);
        }
    }
    
    cout << num << '\n' << maxArea;
}