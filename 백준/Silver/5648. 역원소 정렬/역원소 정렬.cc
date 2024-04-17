#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  while (N--) {
    string s;
    cin >> s;
    
    reverse(s.begin(), s.end());
    v.push_back(stoll(s));
  }
  
  sort(v.begin(), v.end());
  
  for (auto cur : v) cout << cur << '\n';
}