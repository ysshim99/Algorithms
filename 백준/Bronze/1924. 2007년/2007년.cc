#include <bits/stdc++.h>
using namespace std;

string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int x, y;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y;

  int sum = 0;
  for(int i = 1; i < x; ++i) sum += months[i];
  sum += y;

  cout << days[sum % 7];
}