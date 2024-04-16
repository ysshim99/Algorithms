#include <bits/stdc++.h>
using namespace std;

long long cards[100'002];

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for (int i = 0; i < N; ++i) cin >> cards[i];
  cards[N] = INT_MAX;
  
  sort(cards, cards+N);
  
  int cnt = 1;
  int maxCnt = 0;
  long long maxValue = INT_MIN;
  
  for (int i = 1; i <= N; ++i) {
    if (cards[i-1] == cards[i]) cnt++;
    else {
      if (cnt > maxCnt) {
        maxCnt = cnt;
        maxValue = cards[i-1];
      }
      cnt = 1;
    }
  }
  
  cout << maxValue;
}