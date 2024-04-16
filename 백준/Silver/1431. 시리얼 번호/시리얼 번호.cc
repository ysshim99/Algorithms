#include <bits/stdc++.h>
using namespace std;

vector<string> serialnum;

int N;

int sumOfDigits(const string& a) {
  int sum = 0;
  for (int i = 0; i < a.length(); ++i) {
    if (isdigit(a[i])) sum += (a[i] - '0');
  }
  
  return sum;
}

bool comp(const string& a, const string& b) {
  // 길이 비교
  if (a.length() != b.length()) {
    return a.length() < b.length();
  }
  
  // 자릿수 합 비교
  if (sumOfDigits(a) != sumOfDigits(b)) {
    return sumOfDigits(a) < sumOfDigits(b);
  }
  
  // 사전순으로 비교
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  while (N--) {
    string s;
    cin >> s;
    
    serialnum.push_back(s);
  }
  
  sort(serialnum.begin(), serialnum.end(), comp);
  
  for (auto cur : serialnum) cout << cur << '\n';
}