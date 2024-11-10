#include <queue>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> c1, c2, g;
    
    // cards1와 goal을 queue로 나타냄
    for (const string& s : cards1) c1.push(s);
    for (const string& s : cards2) c2.push(s);
    for (const string& s : goal) g.push(s);
    
    // 단어 배열을 앞부터 순회
    while (!g.empty()) {
        // c1의 현재 문자열과 g의 현재 문자열이 일치
        if (!c1.empty() && c1.front() == g.front()) {
            c1.pop();
            g.pop();
        }
        // c2의 현재 문자열과 g의 현재 문자열이 일치
        else if (!c2.empty() && c2.front() == g.front()) {
            c2.pop();
            g.pop();
        }
        // 일치하는 카드 뭉치가 없으면 반복문을 빠져나감
        else
            break;
    }
    
    // 원하는 문자열을 카드 뭉치에서 만들었으면 Yes, 아니면 No 반환
    return g.empty() ? "Yes" : "No";
}