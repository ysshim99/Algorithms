#include <bits/stdc++.h>
using namespace std;

int S[10], W[10];

int N;
int ans = -1;
int cracked = 0; // 깨진 계란의 수

// 현재 cur번째 계란을 들고 있음
void func(int cur) {
  if(cur == N) {
    ans = max(ans, cracked);
    return;
  }

  if(S[cur] <= 0 || cracked == N-1) {
    func(cur+1);
    return;
  }

  for(int i = 0; i < N; ++i) {
    if(S[i] <= 0 || i == cur) continue;

    S[cur] -= W[i];
    S[i] -= W[cur];
    if(S[cur] <= 0) cracked++;
    if(S[i] <= 0) cracked++;

    func(cur+1);

    if(S[cur] <= 0) cracked--;
    if(S[i] <= 0) cracked--;
    S[cur] += W[i];
    S[i] += W[cur];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i) cin >> S[i] >> W[i];

  func(0);

  cout << ans;
}