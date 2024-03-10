#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, int> > point(N);
    for(int i = 0; i < N; ++i)
        cin >> point[i].first >> point[i].second;
    
    sort(point.begin(), point.end());
    
    for(int i = 0; i < N; ++i)
        cout << point[i].first << ' ' << point[i].second << '\n';
}