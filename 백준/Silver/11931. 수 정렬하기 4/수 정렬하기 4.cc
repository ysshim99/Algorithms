#include <bits/stdc++.h>
using namespace std;

bool isUsed[2'000'002];

int N;
const int MXN = 2'000'000;
const int HALF = MXN/2;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  bool isUsed[MXN+2] = {false, };
  while (N--) {
    int num;
    cin >> num;
    
    isUsed[num + HALF] = true;
  }
  
  for (int i = MXN; i >= 0; --i) {
    if (isUsed[i]) cout << i - HALF << '\n';
  }
}