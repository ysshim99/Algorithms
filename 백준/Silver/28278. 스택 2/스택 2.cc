#include <bits/stdc++.h>
using namespace std;

stack<int> s;

enum Order {
  PUSH = 1,
  POP,
  SIZE,
  EMPTY,
  TOP
};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    int order;
    cin >> order;

    switch (order) {
      case PUSH:
        int X;
        cin >> X;

        s.push(X);
        break;
      case POP:
        if (s.empty())
          cout << "-1\n";
        else {
          cout << s.top() << '\n';
          s.pop();
        }
        break;
      case SIZE:
        cout << s.size() << '\n';
        break;
      case EMPTY:
        if (s.empty()) cout << "1\n";
        else cout << "0\n";
        break;
      case TOP:
        if (s.empty()) cout << "-1\n";
        else cout << s.top() << '\n';
        break;
    }
  }
}