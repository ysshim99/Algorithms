#include <bits/stdc++.h>
using namespace std;

int N;

bool isArithmeticSequence(int n) {
  vector<int> nums;
  
  while (n > 0) {
    nums.push_back(n % 10);
    n /= 10;
  }
  
  if (nums.size() <= 1) return true;
  
  int diff = nums[1] - nums[0];
  for (int i = 2; i < nums.size(); ++i) {
    if (nums[i] - nums[i-1] != diff) return false;
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (isArithmeticSequence(i)) cnt++;
  }
  
  cout << cnt;
}