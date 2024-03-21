#include <bits/stdc++.h>
using namespace std;

int dist[200002];

int N, K;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  fill(dist, dist+200000, -1);
  dist[N] = 0;
  deque<int> DQ;
  DQ.push_back(N);

  while(!DQ.empty()) {
    int cur = DQ.front(); DQ.pop_front();

    if(2*cur < 200000 && dist[2*cur] == -1) {
      dist[2*cur] = dist[cur];
      DQ.push_front(2*cur);
    }

    for(int nxt : {cur-1, cur+1}) {
      if(nxt < 0 || nxt >= 200000 || dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      DQ.push_back(nxt);
    }
  }

  cout << dist[K];
}