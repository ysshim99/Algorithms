#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// 문자열로 바뀐 두 수를 조합해서 크기 비교
bool compare(const string &lhs, const string &rhs) {
    return (lhs + rhs) > (rhs + lhs);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    
    for (auto elem : numbers) {
        // numbers의 원소를 문자열로 변형해서 풋
        strings.push_back(to_string(elem));
    }
    
    // 정렬 함수를 기준으로 정렬
    sort(strings.begin(), strings.end(), compare);
    
    // 정렬된 문자열을 앞에서부터 추가
    for (auto elem : strings) {
        answer += elem;
    }
    
    // 최종 숫자가 0이면 0을 반환하고, 그렇지 않으면 answer 반환
    return answer[0] == '0' ? "0" : answer;
}