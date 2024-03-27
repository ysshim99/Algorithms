#include <bits/stdc++.h>
using namespace std;

string A, B;

string string_add(string& A, string& B) {
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());

  while(A.length() < B.length()) A += '0';
  while(A.length() > B.length()) B += '0';

  string result;
  int carry = 0;
  for(int i = 0; i < A.length(); ++i) {
    int sum = A[i]-'0' + B[i]-'0' + carry;
    result += to_string(sum % 10);
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

  cout << string_add(A, B);
}