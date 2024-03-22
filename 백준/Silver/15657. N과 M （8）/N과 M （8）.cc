#include <bits/stdc++.h>
using namespace std;

int selected[10];
int input[10];

int N, M;

// input[start] ~ input[N] 중에서 remain개 선택
// 입력으로 받은 수는 input[1] ~ input[N]에 저장됨
void func(int start, int remain) {
  if(remain == 0) {
    for(int i = 0; i < M; ++i) {
      cout << selected[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for(int i = start; i <= N; ++i) {
    selected[M-remain] = input[i];
    func(i, remain-1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i <N; ++i) {
    cin >> input[i+1];
  }
  sort(input+1, input+1+N);

  func(1, M);
}