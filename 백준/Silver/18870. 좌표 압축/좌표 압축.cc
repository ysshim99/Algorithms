#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  vector<int> X(N), Y(N);

  for(int i = 0; i < N; ++i) cin >> X[i];
  Y = X;

  sort(Y.begin(), Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());

  for(int i = 0; i < N; ++i)
    cout << lower_bound(Y.begin(), Y.end(), X[i]) - Y.begin() << ' ';
}