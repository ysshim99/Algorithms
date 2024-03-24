#include <bits/stdc++.h>
using namespace std;

int N;

bool check(const string& word) {
  bool visited[26] = {false, };
  char prev = word[0];
  visited[word[0] - 'a'] = true;

  for(int i = 1; i < word.length(); ++i) {
    if(word[i] == prev) continue;
    if(visited[word[i] - 'a']) return false;
    visited[word[i] - 'a'] = true;
    prev = word[i];
  }

  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int ans = 0;
  for(int i = 0; i < N; ++i) {
    string word;
    cin >> word;

    if(check(word)) ans++;
  }

  cout << ans;
}