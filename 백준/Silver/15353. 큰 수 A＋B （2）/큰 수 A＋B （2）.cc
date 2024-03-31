#include <bits/stdc++.h>
using namespace std;

string A, B;

string add(string a, string b) {
  string result;
  int carry = 0;
  
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  
  while(a.length() < b.length()) a += '0';
  while(a.length() > b.length()) b += '0';
  
  for(int i = 0; i < a.length(); ++i) {
    int sum = a[i]-'0' + b[i]-'0' + carry;
    result += (sum % 10) + '0';
    carry = sum / 10;
  }
  if(carry) result += '1';
  
  reverse(result.begin(), result.end());
  return result;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> A >> B;
  
  cout << add(A, B);
}