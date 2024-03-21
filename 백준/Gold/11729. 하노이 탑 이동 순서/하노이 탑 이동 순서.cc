#include <bits/stdc++.h>
using namespace std;

/*
hanoi 함수: 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력
기둥: a번, 6-a-b번, b번

처음에는 n-1개의 원판을 a번 기둥에서 6-a-b번 기둥으로 옮긴다.
맨 밑의 원판을 a번 기둥에서 b번 기둥으로 옮긴다. => n = 1일 때
다시 n-1개의 원판을 6-a-b번 기둥에서 b번 기둥으로 옮긴다.

일반항: 2^N - 1
*/

int N;

void hanoi(int a, int b, int n) {
  if(n == 1) {
    cout << a << ' ' << b << '\n';
    return;
  }
  
  hanoi(a, 6-a-b, n-1);
  cout << a << ' ' << b << '\n';
  hanoi(6-a-b, b, n-1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  cout << (1<<N) - 1 << '\n';
  hanoi(1, 3, N);
}