#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> uid;
    
    for (const auto& line : record) {
        // 각 record마다 cmd에는 명령어를 저장하고 id에는 닉네임을 저장
        stringstream ss(line);
        string cmd, id, nickname;
        ss >> cmd >> id;
        
        // 명령어가 Enter 혹은 Change면 nickname에 닉넴임 저장
        if (cmd != "Leave") {
            ss >> nickname;
            uid[id] = nickname;
        }
    }
    
    for (const auto& line : record) {
        stringstream ss(line);
        string cmd, id;
        ss >> cmd >> id;
        
        // Enter 및 Leave 명령어는 최종 닉네임과 정해진 문자열을 answer에 추가
        if (cmd == "Enter") {
            answer.push_back(uid[id] + "님이 들어왔습니다.");
        }
        else if (cmd == "Leave") {
            answer.push_back(uid[id] + "님이 나갔습니다.");
        }
        // Change는 메시지 생성에 영향을 주지 않으므로 무시
    }
    
    return answer;
}