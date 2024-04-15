#include <bits/stdc++.h>
using namespace std;

int arr[10002];

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while (N--) {
    int num;
    cin >> num;

    arr[num]++;
  }

  for (int i = 1; i <= 10000; ++i) {
    while (arr[i]--) cout << i << '\n';
  }
}