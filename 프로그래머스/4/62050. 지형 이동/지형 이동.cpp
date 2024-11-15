#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 현재 칸의 좌표, 이전 칸에서 현재 칸으로 가는 비용
struct Pos {
    int r;
    int c;
    int heightDiff;
    bool operator<(const Pos &p) const { return heightDiff > p.heightDiff; }
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool visited[301][301];

// 다음 이동할 칸이 격자 안 좌표인지 확인
bool isValid(int nr, int nc, int rows, int cols) {
    return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
    int totalCost = 0;
    int rows = land.size(), cols = land[0].size();
    
    priority_queue<Pos> pq;
    pq.push({0, 0, 0});
    
    while (!pq.empty()) {
        Pos current = pq.top();
        pq.pop();
        
        // 이미 방문한 칸은 또 방문하지 않음
        if (visited[current.r][current.c]) continue;
        
        // 현재 칸으로 이동하는 비용을 추가
        totalCost += current.heightDiff;
        
        // 현재 칸의 인접 칸을 순회
        for (int dir = 0; dir < 4; ++dir) {
            int nr = current.r + dy[dir];
            int nc = current.c + dx[dir];
            
            if (isValid(nr, nc, rows, cols)) {
                // 이동할 수 있는 칸과 현재 칸의 높이차
                int diff = abs(land[current.r][current.c] - land[nr][nc]);
                
                // 높이차가 사다리 설치 기준보다 클 때
                if (diff > height)
                    pq.push({nr, nc, diff});
                // 높이차가 사다리 설치 기준보다 크지 않을 때
                else 
                    pq.push({nr, nc, 0});
            }
        }
        
        //현재 칸의 방문 여부
        visited[current.r][current.c] = true;
    }
    
    return totalCost;
}