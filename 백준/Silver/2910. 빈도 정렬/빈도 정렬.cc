#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<pair<int, int>> nums; // {횟수, 수}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> C;
  
  while (N--) {
    int n;
    cin >> n;
    bool isExist = false;
    
    for (auto& num : nums) {
      if (num.second != n) continue;
      num.first++;
      isExist = true;
    }
    
    if (!isExist) nums.push_back({1, n});
  }
  
  stable_sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  });
  
  for (auto num : nums) {
    while (num.first--) cout << num.second << ' ';
  }
}