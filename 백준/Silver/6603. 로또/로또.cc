#include <bits/stdc++.h>
using namespace std;

int S[15];
int selected[15];

int k;

// 현재까지 cnt개 원소 선택
void func(int cnt) {
  if(cnt == 6) {
    for(int i = 0; i < 6; ++i) cout << S[selected[i]] << ' ';
    cout << '\n';
    return;
  }

  int start = 0;
  if(cnt != 0) start = selected[cnt-1] + 1;

  for(int i = start; i < k; ++i) {
    selected[cnt] = i;
    func(cnt+1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true) {
    cin >> k;
    if(k == 0) return 0;

    for(int i = 0; i < k; ++i) cin >> S[i];
    func(0);
    cout << '\n';
  }
}