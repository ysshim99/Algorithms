#include <bits/stdc++.h>
using namespace std;

long long sum(vector<int>& a) {
  long long sum = 0;
  for(auto d : a) sum += d;
  return sum;
}