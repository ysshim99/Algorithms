#include <bits/stdc++.h>
using namespace std;

int input[22];

int N, S;
int cnt;

// 현재까지 selected개 원소 선택, 더한 합 = sum
void func(int selected, int sum) {
  if(selected == N) {
    if(sum == S) cnt++;
    return;
  }

  func(selected+1, sum);
  func(selected+1, sum + input[selected]);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;

  for(int i = 0; i < N; ++i) cin >> input[i];
  func(0, 0);

  // 공집합은 제외
  if(S == 0) cnt--;
  cout << cnt;
}