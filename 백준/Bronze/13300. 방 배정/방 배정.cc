#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

   int N, K;
    cin >> N >> K;
    
    // 남자, 4학년 -> grade[1][4]의 값 1 증가
    int grade[2][7]; fill(&grade[0][0], &grade[2][7], 0);
    for(int i = 0; i < N; ++i) {
        int S, Y;
        cin >> S >> Y;
        
        grade[S][Y]++;
    }
    
    int total = 0;
    for(int i = 0; i < 2; ++i) {
        for(int j = 1; j < 7; ++j) {
            total += grade[i][j]/K;
            
            // K명씩 묶고 남은 사람이 있을 경우
            if(grade[i][j] % K) total++;
        }
    }
    
    cout << total;
}