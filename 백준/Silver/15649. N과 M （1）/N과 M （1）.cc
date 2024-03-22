#include <bits/stdc++.h>
using namespace std;

/*
func: 현재까지 k개 수를 선택했음.
  1. 만약 M개 수를 전부 다 골랐다면
    자신이 고른 수(arr)를 출력
  2. 아직 수를 더 골라야 한다면
    1 ~ N 중 최초로 사용되지 않은 수를 고름
    k번째 수로 i를 선택 -> isUsed[i] = true
    이후 func(k+1) 수행
    탐색이 완료 -> isUsed[i] = false로 변경
*/

int arr[10];
bool isUsed[10];

int N, M;

void func(int k) {
  if(k == M) {
    for(int i = 0; i < M; ++i) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = 1; i <= N; ++i) {
    if(!isUsed[i]) {
      arr[k] = i;
      isUsed[i] = true;
      func(k+1);
      isUsed[i] = false;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  func(0);
}