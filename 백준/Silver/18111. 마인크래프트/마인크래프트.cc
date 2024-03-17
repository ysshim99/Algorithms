#include <bits/stdc++.h>
using namespace std;

int board[502][502];
vector<pair<int, int>> v;

int N, M, B; // board[N][M], 갖고 있는 블록 개수
int maxHight = -1;  // 입력된 땅의 높이 중 최대값
int minHight = INT_MAX; // 입력된 땅의 높이 중 최소값
int minTime = INT_MAX;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> B;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
            minHight = min(minHight, board[i][j]);
            maxHight = max(maxHight, board[i][j]);
        }
    }

    for(int height = minHight; height <= maxHight; ++height) {
        int time = 0;
        int block = B;

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                int diff = height - board[i][j];

                if(diff > 0) { // 블록 쌓기
                    time += diff;
                    block -= diff;
                }
                if(diff < 0) { // 블록 제거
                    time -= 2*diff;
                    block -= diff;
                }
            }
        }
        if(block >= 0) v.push_back({time, height});
    }
    sort(v.begin(), v.end(), comp);

    cout << v.front().first  << ' ' << v.front().second;
}