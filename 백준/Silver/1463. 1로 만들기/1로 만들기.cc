#include <bits/stdc++.h>
using namespace std;

int dist[1'000'002];

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  // initialization
  dist[1] = 0;
  
  for (int i = 2; i <= N; ++i) {
    dist[i] = dist[i-1] + 1;
    if (i % 2 == 0) dist[i] = min(dist[i], dist[i/2] + 1);
    if (i % 3 == 0) dist[i] = min(dist[i], dist[i/3] + 1);
  }
  
  cout << dist[N];
}

// 이 문제는 BFS를 이용해서 풀 수도 있음.