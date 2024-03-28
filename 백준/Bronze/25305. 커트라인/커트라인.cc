#include <bits/stdc++.h>
using namespace std;

int score[1002];

int N, k;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> k;

  for(int i = 0; i < N; ++i) cin >> score[i];
  sort(score, score+N);

  cout << score[N-k];
}