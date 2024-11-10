#include <queue>
#include <string>
#include <vector>

using namespace std;

// 현재 좌표, 해당 좌표까지 이동 횟수
struct Point {
    int y, x, cnt;
};

// 상하좌우로 이동하기 위한 오프셋
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;

bool OOB(int y, int x) {
    return x < 0 || x >= m || y < 0 || y >= n;
}

// 시작 좌표 확인
Point findStartPoint(char start, vector<string> &maps) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == start)
                return {i, j, 0};
        }
    }
    
    // 시작점을 찾지 못한 경우
    return {-1, -1, -1};
}

int bfs(char start, char end, vector<string> &maps) {
    bool visited[101][101] = {false}; // 방문 여부를 체크하는 배열
    queue<Point> q;
    
    q.push(findStartPoint(start, maps)); // 시작 노드부터 너비 우선 탐색하도록 추가
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        // 목적지에 도달했으면 해당 목적지까지 이동 횟수 반환
        if (maps[cur.y][cur.x] == end)
            return cur.cnt;
        
        // 현재 위치 상하좌우 확인
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if (OOB(ny, nx)) continue;
            if (visited[ny][nx] || maps[ny][nx] == 'X') continue;
            
            q.push({ny, nx, cur.cnt + 1});
            visited[ny][nx] = true;
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    // 시작 지점부터 L까지 최단 거리를 구함
    int distanceToL = bfs('S', 'L', maps);
    if (distanceToL == -1) return -1;
    
    // L부터 도착 지점까지 최단 거리를 구함
    int distanceToE = bfs('L', 'E', maps);
    return distanceToE == -1 ? -1 : distanceToL + distanceToE;
}