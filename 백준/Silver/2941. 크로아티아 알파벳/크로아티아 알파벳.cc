#include <bits/stdc++.h>
using namespace std;

string input;
string croatianAlpha[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  for(const string& alpha : croatianAlpha) {
    size_t pos = input.find(alpha);

    while(pos != string::npos) {
      input.replace(pos, alpha.length(), "a");
      pos = input.find(alpha, pos+1);
    }
  }

  cout << input.length();
}