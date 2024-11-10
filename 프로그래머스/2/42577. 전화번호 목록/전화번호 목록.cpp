#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phoneBook) {
    // 전화번호 목록을 오름차순으로 정렬
    sort(phoneBook.begin(), phoneBook.end());
    
    // 모든 전화번호를 순회하며 다음 번호와 비교
    for (int i = 0; i < phoneBook.size() - 1; ++i) {
        // 현재 번호가 다음 번호의 접두어이면 false
        if (phoneBook[i] == phoneBook[i + 1].substr(0, phoneBook[i].size()))
            return false;
    }
    
    // 어떤 번호도 다른 번호의 접두어가 아니면 true
    return true;
}