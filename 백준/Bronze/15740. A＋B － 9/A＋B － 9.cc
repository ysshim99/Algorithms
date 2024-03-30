#include <bits/stdc++.h>
using namespace std;

string A, B;

bool isPositive(const string& a) {
  return a[0] != '-';
}

// a & b는 양수, a와 b가 같으면 true 반환
bool isFormerBiggerThanLater(const string& a, const string& b) {
  if(a.size() != b.size()) return a.size() > b.size();
  
  for(int i = a.size()-1; i >= 0; --i) {
    if(a[i] == b[i]) continue;
    return a[i] > b[i];
  }
  
  return true;
}

// a & b는 양수
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

// a & b는 양수, a-b 출력
string substract(string a, string b) {
  string result;
  int borrow = 0;
  
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  
  while(a.length() > b.length()) b += '0';
  
  for(int i = 0; i < a.length(); ++i) {
    int sum = (a[i]-'0') - (b[i]-'0') - borrow;
    
    if(sum < 0) {
      sum += 10;
      borrow = 1;
    }
    else {
      borrow = 0;
    }
    
    result += sum + '0';
  }
  
  while(result.length() > 1 && result.back() == '0')
    result.pop_back();
  
  reverse(result.begin(), result.end());
  return result;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> A >> B;
  
  if(isPositive(A) && isPositive(B))
    cout << add(A, B) << '\n';
  else if(!isPositive(A) && !isPositive(B))
    cout << '-' << add(A.substr(1), B.substr(1)) << '\n';
  else if(isPositive(A) && !isPositive(B)) {
    B = B.substr(1);
    
    if(isFormerBiggerThanLater(A, B)) cout << substract(A, B) << '\n';
    else cout << '-' << substract(B, A) << '\n';
  }
  else {    
    A = A.substr(1);
    
    if(isFormerBiggerThanLater(A, B)) {
      string result = substract(A, B);
      
      if(result == "0") cout << result << '\n';
      else cout << '-' << result << '\n';
    }
    else cout << substract(B, A);
  }
}