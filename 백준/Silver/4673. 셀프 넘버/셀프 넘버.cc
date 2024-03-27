#include <bits/stdc++.h>
using namespace std;

int arr[10002];

void func(int n) {
  int sum = n;
  while(n) {
    sum += n%10;
    n /= 10;
  }

  if(sum <= 10000) arr[sum]++;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <= 10000; ++i) func(i);

  for(int i = 1; i <= 10000; ++i)
    if(arr[i] == 0) cout << i << '\n';
}