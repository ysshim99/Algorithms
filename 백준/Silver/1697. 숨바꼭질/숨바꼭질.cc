#include <bits/stdc++.h>
using namespace std;

/*
nxt > 100000이 되면 뒤로 돌아오는 건 한 칸 씩만 가능하므로 굉장히 손해다.
nxt < 0이 되어도 앞으로 가기 위해선 한 칸 씩만 가능하므로 손해다.
*/

int dist[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    
    fill(dist, dist+100002, -1);
    dist[N] = 0;
    
    queue<int> Q;
    Q.push(N);
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if(cur == K) {
            cout << dist[K];
            return 0;
        }
        
        for(int nxt : {cur-1, cur+1, 2*cur}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(dist[nxt] >= 0) continue;
            
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
}
