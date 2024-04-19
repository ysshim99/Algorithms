#include <bits/stdc++.h>
using namespace std;

int T;
int N, M;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  
  while (T--) {
    cin >> N >> M;
    vector<pair<int, int>> v;
    
    while (N--) {
      int a;
      cin >> a;
      
      v.push_back({a, 0});
    }
    
    while (M--) {
      int b;
      cin >> b;
      
      v.push_back({b, 1});
    }
    
    // A 이전에 나온 B의 개수를 count
    sort(v.begin(), v.end());
    
    int cnt = 0, ans = 0; // cnt: 현재까지 나온 B의 개수
    for (auto cur : v) {
      if (cur.second) cnt++; // B의 원소
      else ans += cnt;       // A의 원소
    }
    
    cout << ans << '\n';
  }
}