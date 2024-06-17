#include <bits/stdc++.h>
using namespace std;

int N;  // 회의의 수

pair<int, int> schedule[100005];  // {end, start}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i)
    cin >> schedule[i].second >> schedule[i].first;

  sort(schedule, schedule + N);

  int ans = 0;  // 회의의 개수
  int t = 0;    // 현재 시각

  for (int i = 0; i < N; ++i) {
    if (t > schedule[i].second) continue;
    ans++;
    t = schedule[i].first;
  }

  cout << ans;
}