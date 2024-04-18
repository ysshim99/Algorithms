#include <bits/stdc++.h>
using namespace std;

int N;
vector<tuple<int, int, int, string>> scores;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  while (N--) {
    string name;
    int korscore, engscore, mathscore;
    cin >> name >> korscore >> engscore >> mathscore;
    
    scores.push_back({-korscore, engscore, -mathscore, name});
  }
  
  sort(scores.begin(), scores.end());
  
  for (auto score : scores) cout << get<3>(score) << '\n';
}