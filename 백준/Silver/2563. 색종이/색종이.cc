#include <bits/stdc++.h>
using namespace std;

bool isBlack[100][100];

int N;
int area;

void paint(int y, int x) {
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j < 10; ++j) {
      if(!isBlack[y+i][x+j]) {
        isBlack[y+i][x+j] = true;
        area++;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  while(N--) {
    int x, y;
    cin >> x >> y;
    
    paint(y, x);
  }

  cout << area;
}