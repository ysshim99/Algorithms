#include <bits/stdc++.h>
using namespace std;

string word[5];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; ++i) cin >> word[i];

  for(int col = 0; col < 15; ++col) {
    for(int row = 0; row < 5; ++row) {
      if(word[row][col]) cout << word[row][col];
    }
  }
}