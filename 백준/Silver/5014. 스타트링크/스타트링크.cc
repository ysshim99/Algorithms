#include <bits/stdc++.h>
using namespace std;

int dist[1000002]; // 눌러야 하는 버튼의 수 (F층: dist[F])
queue<int> Q;

int F, S, G; // F(건물의 층수) S(현 위치) G(목적지)
int U, D;   // U(위로) D(아래로)
bool flag;  // 원하는 층수에 도달했으면 true, 아니면 false

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> F >> S >> G >> U >> D;
    
    fill(dist, dist+F+1, -1);
    dist[S] = 0;
    Q.push(S);
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur == G) flag = true;
        
        for(int nxt : {cur-D, cur+U}) {
            if(nxt <= 0 || nxt > F) continue;
            if(dist[nxt] >= 0) continue;
            
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    
    if(flag) cout << dist[G];
    else cout << "use the stairs";
}