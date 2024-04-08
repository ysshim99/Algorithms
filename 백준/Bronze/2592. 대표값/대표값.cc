#include <bits/stdc++.h>
using namespace std;

int arr[1001];
pair<int, int> ans; // 횟수, 수

int sum, num;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for(int i = 0; i < 10; ++i) {
    cin >> num;
    
    sum += num;
    arr[num]++;
    
    if(ans.first < arr[num]) {
      ans.first = arr[num];
      ans.second = num;
    }
  }
  
  cout << sum / 10 << '\n' << ans.second;
}