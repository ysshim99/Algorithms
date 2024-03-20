#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int K, N;
int max_len = INT_MIN;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K >> N;

  for(int i = 0; i < K; ++i) {
    int num;
    cin >> num;

    arr.push_back(num);
    max_len = max(max_len, num);
  }

  long long left = 1, right = max_len, mid;
  int len = 0;

  while(left <= right) {
    mid = left + (right - left) / 2;
    int cnt = 0;

    for(int i = 0; i < K; ++i) {
      cnt += arr[i] / mid;
    }

    if(cnt >= N) {
      left = mid + 1;
      if(len < mid) len = mid;
    }
    else {
      right = mid - 1;
    }
  }

  cout << len;
}