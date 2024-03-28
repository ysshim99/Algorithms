#include <bits/stdc++.h>
using namespace std;

string input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  sort(input.begin(), input.end(), greater<int>());

  cout << input;
}