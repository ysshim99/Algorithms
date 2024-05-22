#include <bits/stdc++.h>
using namespace std;

int menu[10];

int N, M;
int ans;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> menu[i];
  
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int corner;
    cin >> corner;
    ans += menu[corner - 1];
  }
  
  cout << ans;
}