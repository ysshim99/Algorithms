#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int N;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while(N--) {
    int num;
    cin >> num;

    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for(auto d : v) cout << d << '\n';
}