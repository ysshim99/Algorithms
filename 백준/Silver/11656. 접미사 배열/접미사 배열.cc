#include <bits/stdc++.h>
using namespace std;

string S;
vector<string> suffixes;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> S;
  
  for (int i = 0; i < S.length(); ++i)
    suffixes.push_back(S.substr(i));
  
  sort(suffixes.begin(), suffixes.end());
  
  for (auto suffix : suffixes) cout << suffix << '\n';
}