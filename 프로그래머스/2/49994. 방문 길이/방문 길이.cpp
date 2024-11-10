#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool visited[11][11][4];

int todir(char dir) {
    if (dir == 'U') return 0;
    if (dir == 'R') return 1;
    if (dir == 'D') return 2;
    if (dir == 'L') return 3;
}

bool OOB(int x, int y) {
    return x < 0 || x > 10 || y < 0 || y > 10;
}

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    for (auto c : dirs) {
        int dir = todir(c);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (OOB(nx, ny)) continue;
        
        if (visited[y][x][dir] == false) {
            visited[y][x][dir] = true;
            visited[ny][nx][(dir + 2) % 4] = true;
            answer++;
        }
        
        x = nx;
        y = ny;
    }
    
    return answer;
}