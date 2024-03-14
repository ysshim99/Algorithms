#include <bits/stdc++.h>
using namespace std;

// pair.first(second) -> pair.Y(X)
#define Y first
#define X second

string board[102];
bool visited[102][102];
queue<pair<int, int> > Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;

void bfs(int y, int x) {
	char c = board[y][x];
	visited[y][x] = true;
	Q.push({y, x});

	while(!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for(int dir = 0; dir < 4; ++dir) {
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if(board[ny][nx] != c || visited[ny][nx] == true) continue;

			visited[ny][nx] = true;
			Q.push({ny, nx});
		}
	}
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

	for(int i = 0; i < N; ++i) {
		cin >> board[i];
	}

	// 적록색약이 아닌 사람
	int cnt1 = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(visited[i][j] == false) {
				bfs(i, j);
				cnt1++;
			}
		}
	}

	// 적록색약인 사람
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(board[i][j] == 'G') board[i][j] = 'R';
		}
	}
	for(int i = 0; i < N; ++i) {
		fill(visited[i], visited[i]+102, false);
	}

	int cnt2 = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(visited[i][j] == false) {
				bfs(i, j);
				cnt2++;
			}
		}
	}
	cout << cnt1 << ' ' << cnt2;
}
