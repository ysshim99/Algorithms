#include <bits/stdc++.h>
using namespace std;

int arr[22];

int M;
string op;
int num;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M;

  while(M--) {
    cin >> op;

    if(op == "add") {
      cin >> num;

      if(!arr[num]) arr[num]++;
    }
    if(op == "remove") {
      cin >> num;

      if(arr[num]) arr[num]--;
    }
    if(op == "check") {
      cin >> num;

      if(arr[num]) cout << "1\n";
      else cout << "0\n";
    }
    if(op == "toggle") {
      cin >> num;

      if(arr[num]) arr[num]--;
      else arr[num]++;
    }
    if(op == "all") {
      for(int i = 1; i <= 20; ++i) arr[i] = 1;
    }
    if(op == "empty") {
      for(int i = 1; i <= 20; ++i) arr[i] = 0;
    }
  }
}