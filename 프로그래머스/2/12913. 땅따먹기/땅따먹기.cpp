#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land) {
    // 각 행마다 이전 행의 최대 점수를 더해가며 최대 점수 누적
    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            // 이전 행에서 현재 열의 값을 제외한 나머지 열 중 가장 큰 값을 더함
            int maxVal = 0;
            for (int k = 0; k < 4; ++k) {
                if (k != j)
                    maxVal = max(maxVal, land[i - 1][k]);
            }
            
            land[i][j] += maxVal;
        }
    }
    
    // 마지막 행에서 얻을 수 있는 최대 점수 반환
    return *max_element(land.back().begin(), land.back().end());
}