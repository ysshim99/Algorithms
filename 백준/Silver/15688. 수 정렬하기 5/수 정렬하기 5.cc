#include <bits/stdc++.h>
using namespace std;

const int MXN = 2'000'000, HALF = MXN/2;
int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  int arr[MXN+2] = {0, };
  while (N--) {
    int num;
    cin >> num;
    
    arr[num + HALF]++;
  }
  
  for (int i = 0; i <= MXN; ++i) {
    while (arr[i]--) cout << i - HALF << '\n';
  }  
}