#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

enum Order {
  PUSH_FRONT = 1,
  PUSH_BACK,
  POP_FRONT,
  POP_BACK,
  SIZE,
  EMPTY,
  FRONT,
  BACK
};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N;
  cin >> N;
  
  while(N--) {
    int order, X;
    cin >> order;
    
    switch(order) {
      case PUSH_FRONT:
        cin >> X;
        dq.push_front(X);
        break;
      case PUSH_BACK:
        cin >> X;
        dq.push_back(X);
        break;
      case POP_FRONT:
        if(dq.empty()) cout << "-1\n";
        else {
          cout << dq.front() << '\n';
          dq.pop_front();
        }
        break;
      case POP_BACK:
        if(dq.empty()) cout << "-1\n";
        else {
          cout << dq.back() << '\n';
          dq.pop_back();
        }
        break;
      case SIZE:
        cout << dq.size() << '\n';
        break;
      case EMPTY:
        if(dq.empty()) cout << "1\n";
        else cout << "0\n";
        break;
      case FRONT:
        if(dq.empty()) cout << "-1\n";
        else cout << dq.front() << '\n';
        break;
      case BACK:
        if(dq.empty()) cout << "-1\n";
        else cout << dq.back() << '\n';
        break;
    }
  }
}