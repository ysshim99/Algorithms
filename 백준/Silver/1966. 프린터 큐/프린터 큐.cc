#include <bits/stdc++.h>
using namespace std;

/*
이 문제에서 중요한 점은
특정 문서를 추적하기 위해 index와 importance를 쌍으로 묶은 것이다.

뒤에 중요도가 더 높은 문서가 있을 경우 = PQ.top() > importance
    해당 문서를 맨 뒤로 보냄.
그렇지 않을 경우
    인쇄
    만약 해당 문서가 내가 조사하는 문서라면
        cnt 출력 and 종료
*/

queue<pair<int, int> > doc; // 맨 처음 입력받은 문서 정보 저장
priority_queue<int> pq;
int importance, idx; // importance: 중요도, idx: 조사할 문서의 위치
int cnt = 0; // 인쇄 횟수

int T, N, M; // T: test case, N: 문서의 개수, M: 조사할 문서의 위치

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while(T--) {
		cin >> N >> M;
        
        // initialization
        doc = {}; pq = {};
        cnt = 0;

		for(int i = 0; i < N; ++i) {
			cin >> importance;
			doc.push({i, importance});
			pq.push(importance);
		}

		while(!doc.empty()) {
			idx = doc.front().first;
			importance = doc.front().second;

			if(pq.top() > importance) {
				doc.push(doc.front());
				doc.pop();
			}
			else {
				doc.pop();
				pq.pop();
				cnt++;

				if(idx == M) {
					cout << cnt << '\n';
					break;
				}
			}
		}
	}
}