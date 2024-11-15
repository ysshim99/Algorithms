#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
    // 크기에 따른 귤의 개수를 세는 counter
    unordered_map<int, int> counter;
    
    // 크기별로 귤의 개수를 셈
    for (int i = 0; i < tangerine.size(); ++i)
        counter[tangerine[i]]++;
    
    // 각 귤의 개수만 저장 후 내림차순 정렬
    vector<int> sorted_counts;
    for (const auto &kv : counter) {
        sorted_counts.push_back(kv.second);
    }
    sort(sorted_counts.rbegin(), sorted_counts.rend());
    
    int num_types = 0; // 현재까지 고른 귤의 종류
    int count_sum = 0; // 현재까지 귤 개수의 총 합
    
    // 가장 많은 귤의 개수부터 순회
    for (int count : sorted_counts) {
        count_sum += count;
        num_types++;
        
        // 귤의 개수 합이 k이상 되면 종료
        if (count_sum >= k) break;
    }
    
    return num_types;
}