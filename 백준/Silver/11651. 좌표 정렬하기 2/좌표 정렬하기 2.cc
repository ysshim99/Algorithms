#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  pair<int, int> pos[N];
  for (auto& cur : pos) cin >> cur.Y >> cur.X;
  
  sort(pos, pos+N);
  
  for (auto cur : pos) cout << cur.Y << ' ' << cur.X << '\n';
}