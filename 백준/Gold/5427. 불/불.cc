#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; //불에 대한 BFS
int dist2[1002][1002]; //상근이에 대한 BFS
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int w,h; //w는 열 , h는 행

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T; //테스트 케이스의 수

    while(T--){
        bool escape = false;
        cin >> w >> h;
        for(int i=0;i<h;i++){
            cin >> board[i];
            fill(dist1[i],dist1[i]+w,-1);
            fill(dist2[i],dist2[i]+w,-1);
        }
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]=='*'){ //불이 난 위치
                    q1.push({i,j});
                    dist1[i][j] = 0;
                }
                if(board[i][j]=='@'){ //상근이의 시작 위치
                    q2.push({i,j});
                    dist2[i][j] = 0;
                }
            }
        }
        //==불의 전파==//
        while(!q1.empty()){
            auto cur = q1.front(); q1.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny <0 || nx>=h || ny >=w) continue;
                if(dist1[nx][ny]>=0 || board[nx][ny]=='#') continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
                q1.push({nx,ny});
            }
        }
        //==상근이의 이동==//
        while(!q2.empty()&&(!escape)){
            auto cur = q2.front(); q2.pop();
            for(int dir=0; dir<4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0 || ny <0 || nx>=h || ny >=w) { //범위를 벗어난 것은 탈출을 의미.
                    cout << dist2[cur.X][cur.Y]+1 << '\n';
                    escape = true;
                    break;
                }
                if(dist2[nx][ny]>=0 || board[nx][ny]=='#') continue;
                if(dist1[nx][ny]!=-1 && dist1[nx][ny]<=dist2[cur.X][cur.Y]+1) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                q2.push({nx,ny});
            }
        }
        if(!escape)
            cout <<"IMPOSSIBLE" << '\n';
    }
    return 0;
}