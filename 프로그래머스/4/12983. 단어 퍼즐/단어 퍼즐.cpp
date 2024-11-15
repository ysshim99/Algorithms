#include <algorithm>
#include <limits>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<string> strs, string t) {
    int INF = numeric_limits<int>::max();
    int n = t.length(); // 타겟 문자열의 t의 길이
    vector<long long> dp(n + 1, INF); // 위치별 필요한 최소 조각수를 저장할 벡터
    dp[0] = 0; // 빈 문자열을 얻기 위한 최소 조각수는 0
    
    unordered_set<int> sizes; // strs 조각들의 길이를 저장한 셋
    for (const auto &s : strs)
        sizes.insert(s.length());
    
    // strs의 원소를 저장한 셋
    unordered_set<string> strsSet(strs.begin(), strs.end());
    
    for (int i = 1; i <= n; ++i) {
        // 각 str 조각의 문자열 길이에 대하여
        for (int size : sizes) {
            // 이미 구한 해와 str 조각을 추가해서 문자열을 만들 수 있다면
            if (i >= size && strsSet.count(t.substr(i - size, size))) {
                dp[i] = min(dp[i], dp[i - size] + 1); // 해당 위치의 최소 조각수를 갱신
            }
        }
    }
    
    return dp[n] != INF ? dp[n] : -1; // 최소 조각수를 반환 (만들 수 없다면 -1)
}