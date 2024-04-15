#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  pair<int, string> user[N];
  for (auto& cur :  user) cin >> cur.first >> cur.second;
  
  stable_sort(user, user+N, [&](pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
  });
  
  for (auto cur : user) cout << cur.first << ' ' << cur.second << '\n';
}