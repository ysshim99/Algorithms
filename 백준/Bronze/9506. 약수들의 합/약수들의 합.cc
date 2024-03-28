#include <bits/stdc++.h>
using namespace std;

void pnum(int n) {
  vector<int> div;
  int sum = 0;

  for(int i = 1; i < n; ++i) {
    if(n % i == 0) {
      sum += i;
      div.push_back(i);
    }
  }

  if(sum == n) {
    cout << n << " = " << div[0];
    for(int i = 1; i < div.size(); ++i)
      cout << " + " << div[i];
    cout << '\n';
  }
  else {
    cout << n << " is NOT perfect.\n";
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int input;
  while(true) {
    cin >> input;
    if(input == -1) return 0;

    pnum(input);
  }
}