#include <bits/stdc++.h>
using namespace std;

int chess[51][51]; // Black : 0, White : 1

int WB[8][8] = {
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1
};

int BW[8][8] = {
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0,
    0, 1, 0, 1, 0, 1, 0, 1,
    1, 0, 1, 0, 1, 0, 1, 0
};

int countBlock(int x, int y) {
    int cnt1 = 0, cnt2 = 0;
    
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            cnt1 += abs(chess[x+i][y+j] - WB[i][j]);
    
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            cnt2 += abs(chess[x+i][y+j] - BW[i][j]);

    return min(cnt1, cnt2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            
            if(c == 'B') chess[i][j] = 0;
            else if(c == 'W') chess[i][j] = 1;
        }
    }
    
    int result = 64;
    for(int i = 0; i <= N-8; ++i)
        for(int j = 0; j <= M-8; ++j)
            result = min(result, countBlock(i, j));
    
    cout << result;  
}