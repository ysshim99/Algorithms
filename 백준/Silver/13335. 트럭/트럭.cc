#include <bits/stdc++.h>
using namespace std;

int bridge[102];
queue<int> trucks;

int n, L, maxWeight;
int weightOnBridge, crossingTime;

void moveTrucksToLeft() {
  for (int i = 0; i < L-1; ++i) {
    bridge[i] = bridge[i+1];
  }
  bridge[L-1] = 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> L >> maxWeight;

  while (n--) {
    int weight;
    cin >> weight;
    trucks.push(weight);
  }

  while (!trucks.empty()) {
    crossingTime++;
    weightOnBridge -= bridge[0];
    moveTrucksToLeft();
    
    if (weightOnBridge + trucks.front() > maxWeight) continue;
    weightOnBridge += trucks.front();
    bridge[L-1] = trucks.front();
    trucks.pop();
  }

  cout << crossingTime + L;
}