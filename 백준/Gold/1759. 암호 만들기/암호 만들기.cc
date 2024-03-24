#include <bits/stdc++.h>
using namespace std;

char input[20];
int selected[20];
bool used[20];

int L, C;
int cnt; // 모음 개수

// 모음인지 확인
bool check(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// 현재까지 cur개 알파벳 선택
void func(int cur) {
  if (cur == L) {
    if (1 <= cnt && cnt <= L-2) {
      for (int i = 0; i < L; ++i) cout << input[selected[i]];
      cout << '\n';
    }
    return;
  }

  int start = 0;
  if (cur != 0) start = selected[cur - 1] + 1;

  for (int i = start; i < C; ++i) {
    if (!used[i]) {
      selected[cur] = i;
      if(check(input[i])) cnt++;
      used[i] = true;
      func(cur + 1);
      if(check(input[i])) cnt--;
      used[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;

  for (int i = 0; i < C; ++i) cin >> input[i];
  sort(input, input + C);

  func(0);
}

/*
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> C;

  for (int i = 0; i < C; i++) cin >> input[i];
  sort(input, input + C);

  vector<int> brute(C);
  for (int i = L; i < C; i++) brute[i] = 1;

  do {
    string keys;
    int cnt = 0;  // 모음의 수

    for (int i = 0; i < C; i++) {
      if (brute[i] == 0) {
        keys += input[i];
        if (check(input[i])) cnt++;
      }
    }

    if (cnt < 1 || L - cnt < 2) continue;
    cout << keys << '\n';
  } while (next_permutation(brute.begin(), brute.end()));
}
*/