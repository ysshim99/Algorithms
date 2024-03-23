#include <bits/stdc++.h>
using namespace std;

string name[100002];
map<string, int> m;

int N, M;
string input;  

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; ++i) {
    cin >> name[i];
    m.insert(make_pair(name[i], i));
  }

  while(M--) {
    cin >> input;

    if(isdigit(input[0])) {
      int idx = stoi(input);
      cout << name[idx] << '\n';
    }
    else {
      auto idx = m.find(input);
      cout << idx->second << '\n';
    }
  }
}