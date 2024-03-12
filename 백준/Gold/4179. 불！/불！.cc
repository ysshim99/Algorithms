#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)로 사용
#define Y first
#define X second

/*
불이 난 위치 or 지훈이의 초기 위치에 대하여
queue에 push and dist = 0으로 한다.

불에 대해 BFS를 수행한다.

지훈이에 대해 BFS를 수행한다.
    만약, 지훈이가 다음 차례에 미로의 밖에 있다면, 미로를 탈출했다는 의미이므로
        탈출하는데 걸리는 시간(dist2 + 1)을 출력 and 종료한다.
    만약, 다음 위치가 이미 조사했던 점(dist2 >= 0)이거나 벽(board = '#')이라면,
        무시한다.
    만약, 지훈이가 도달할 다음 위치가 이미 불이 났거나 or 1초 뒤에 도달할 위치라면,
        (불이 도착한다는 가정이 있으므로 dist1 >= 0 이어야 한다.)
        무시한다.
    그 외의 경우는 똑같이 dist2 + 1 and queue에 push 한다.
    
지훈이에 대해 BFS를 수행하는 동안 while문이 종료되지 않았다면, 
탈출하지 못한 것이다. 

dist1 : 해당 위치까지 불이 도달하는데 걸리는 시간
Q1 : 불에 대한 큐
dist2 : 해당 위치까지 지훈이가 가는데 걸리는 시간
Q2 : 지훈이에 대한 큐
*/

string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R, C;
    cin >> R >> C;
    
    for(int i = 0; i < R; ++i) {
        fill(dist1[i], dist1[i]+C, -1);
        fill(dist2[i], dist2[i]+C, -1);
    }
    
    for(int i = 0; i < R; ++i)
        cin >> board[i];
    
    queue<pair<int, int> > Q1;
    queue<pair<int, int> > Q2;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < R; ++j) {
            if(board[i][j] == 'F') {
                dist1[i][j] = 0;
                Q1.push({i, j});
            }
            
            if(board[i][j] == 'J') {
                dist2[i][j] = 0;
                Q2.push({i, j});
            }
        }
    }
    
    while(!Q1.empty()) {
        auto cur = Q1.front();
        Q1.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if(dist1[ny][nx] >= 0 || board[ny][nx] == '#') continue;
            
            dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
            Q1.push({ny, nx});
        }
    }
    
    while(!Q2.empty()) {
        auto cur = Q2.front();
        Q2.pop();
        
        for(int dir = 0; dir < 4; ++dir) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) {
                cout << dist2[cur.Y][cur.X] + 1;
                return 0;
            }
            
            if(dist2[ny][nx] >= 0 || board[ny][nx] == '#') continue;
            if(dist1[ny][nx] >= 0 && dist1[ny][nx] <= dist2[cur.Y][cur.X] + 1) continue;
            
            dist2[ny][nx] = dist2[cur.Y][cur.X] + 1;
            Q2.push({ny, nx});
        }
    }
    
    cout << "IMPOSSIBLE";
}