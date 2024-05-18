#include <bits/stdc++.h>
using namespace std;

string subjects[16];

int N, ans;
string retake;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> retake;
  cin >> N;
  
  for (int i = 0; i < N; ++i) {
    cin >> subjects[i];
    
    ans += (retake.substr(0, 5) == subjects[i].substr(0, 5));
  }
  
  cout << ans;
}