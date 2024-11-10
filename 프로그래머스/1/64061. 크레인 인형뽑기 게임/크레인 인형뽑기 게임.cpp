#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> lanes[board[0].size()];
    
    // 보드 가장 밑의 행부터 위로 올라가며 순회
    for (int i = board.size() - 1; i >= 0; --i) {
        for (int j = 0; j < board[0].size(); ++j) {
            // 블럭이 있으면 해당 열을 스택에 푸시
            if (board[i][j]) lanes[j].push(board[i][j]);
        }
    }
    
    // 보드판에서 꺼낸 인형을 담을 bucket, 사라진 인형의 개수를 저장할 answer 선언
    stack<int> bucket;
    int answer = 0;

    for (int m : moves) {
        // 해당 lane에 블럭이 있으면
        if (lanes[m - 1].size()) {
            int doll = lanes[m - 1].top();
            lanes[m - 1].pop();
        
            // bucket에 블럭이 있고, 가장 최근에 들어간 블럭과 현재 블럭이 같은지 확인
            if (bucket.size() && bucket.top() == doll) {
                bucket.pop();
                answer += 2;
            }
            else {
                bucket.push(doll);
            }
        }
    }
    
    return answer;
}



