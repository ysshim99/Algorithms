#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end()); // 몸무게를 오름차순으로 정렬
    
    int count = 0; // 필요한 보트 개수
    int i = 0; // 가장 가벼운 사람을 가리키는 인덱스
    int j = people.size() - 1; // 가장 무거운 사람을 가리키는 인덱스
    
    while (i <= j) {
        // 가장 무거운 사람과 가장 가벼운 사람을 같이 태울 수 있으면 두 사람 모두 보트에 태움
        if (people[i] + people[j] <= limit)
            i++;
        // 무거운 사람만 태울 수 있으면 무거운 사람만 보트에 태움
        j--;
        count++;
    }
    
    return count;
}