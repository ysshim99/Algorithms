#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end()); // 벡터 d를 오름차순으로 정렬
    int count = 0; // 지원할 수 있는 부서의 개수를 세는 변수
    
    for (int amount : d) {
        // 남은 예산이 신청한 금액보다 작으면 더 이상 지원할 수 없으므로 종료
        if (budget < amount) break;
        
        budget -= amount; // 예산에서 신청한 금액 차감
        count += 1;
    }
    
    return count;
}