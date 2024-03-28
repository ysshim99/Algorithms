#include <bits/stdc++.h>
using namespace std;

int x[100002], y[100002];

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; ++i)
    cin >> x[i] >> y[i];
  
  sort(x, x+N); sort(y, y+N);

  cout << (x[N-1] - x[0]) * (y[N-1] - y[0]);
}