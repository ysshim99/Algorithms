#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  vector<string> words(N);
  for (int i = 0; i < N; ++i) cin >> words[i];
  
  sort(words.begin(), words.end(), [](const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
  });
  
  words.erase(unique(words.begin(), words.end()), words.end());
  
  for (auto word : words) cout << word << '\n';
}