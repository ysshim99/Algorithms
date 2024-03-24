#include <bits/stdc++.h>
using namespace std;

string N;
int B;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> B;

  int sum = 0;
  int digit, pow = 1;
  
  for(int i = N.length()-1; i >= 0; --i) {
    if(isdigit(N[i])) digit = N[i]-'0';
    else digit = N[i]-'A'+10;

    sum += digit*pow;
    pow *= B;
  }

  cout << sum;
}