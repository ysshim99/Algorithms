#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string, string> parent;
    
    // parent는 판매원 - 판매원을 참여시킨 추천인으로 구성
    for (size_t i = 0; i < enroll.size(); ++i) {
        parent[enroll[i]] = referral[i];
    }
    
    unordered_map<string, int> total;
    // total은 판매원 - 판매원의 수익으로 구성, 수익을 0으로 초기화
    for (const auto &name : enroll) {
        total[name] = 0;
    }
    
    for (size_t i = 0; i < seller.size(); ++i) {
        int money = amount[i] * 100; // 현재 판매원의 수익금
        string cur_name = seller[i]; // 실제 물건을 판 사람
        
        while (money > 0 && cur_name != "-") {
            // 실제 물건을 판 사람을 기준으로 추천인을 계속 추적하며 남은 수익의 10%를 분배
            int to_distribute = money / 10;
            total[cur_name] += money - to_distribute;
            
            // 현재 이름의 추천인이 있으면 현재 이름을 추천인으로 번경, 그렇지 않으면 종료
            if (parent.find(cur_name) != parent.end()) {
                cur_name = parent[cur_name];
            }
            else 
                break;
            
            // 현재 판매원이 추천인으로 변경되었으므로 수익금도 이에 맞춰 업데이트
            money = to_distribute;
        }
    }
    
    // 수익금을 answer에 업데이트해서 반환
    vector<int> result;
    result.reserve(enroll.size());
    for (const auto &name : enroll) {
        result.push_back(total[name]);
    }
    
    return result;
}