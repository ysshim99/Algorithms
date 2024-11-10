#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 100;
int check[MAX_SIZE][MAX_SIZE];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 좌표 정보 및 좌표 연산을 하기 위한 구조체
struct Point {
    int y, x;
    
    Point(int y, int x) : y(y), x(x) {}
    
    bool OOB(int width, int height) {
        return x < 0 || x >= width || y < 0 || y >= height;
    }
    
    Point move(int i) const { return Point(y + dy[i], x + dx[i]); }
    
    bool canMoveTo(const vector<vector<int>> &maps) const {
        return maps[y][x] == 1 && check[y][x] == 0;
    }
};

queue<Point> q; // BFS를 위한 큐

int solution(vector<vector<int>> maps) {
    int width = maps[0].size(), height = maps.size();
    q.push({0, 0});
    check[0][0] = 1;
    
    // 너비 우선 탐색 진행
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        // 현재 좌표 기준으로 상하좌우를 확인
        for (int dir = 0; dir < 4; ++dir) {
            Point next = cur.move(dir);
            
            if (next.OOB(width, height)) continue;
            if (!next.canMoveTo(maps)) continue;
            
            // 범위가 좌표이고 벽이 아닌 경우
            check[next.y][next.x] = check[cur.y][cur.x] + 1;
            q.push({next.y, next.x});
        }
    }
    
    // 목적지 도달 가능 여부 확인
    int dstX = width - 1, dstY = height - 1;
    // 도착 지점에 도달할 수 없음
    if (check[dstY][dstX] == 0)
        return -1;
    
    // 도착 지점까지 최단 거리 반환
    return check[dstY][dstX];
}