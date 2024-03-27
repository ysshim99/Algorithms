#include <bits/stdc++.h>
using namespace std;

string input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  for(int i = 0; i < input.length(); i += 10)
    cout << input.substr(i, 10) << '\n';
}