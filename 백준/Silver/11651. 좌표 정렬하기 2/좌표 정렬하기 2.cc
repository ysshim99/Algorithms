#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100002];
int N;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr+N, comp);
    
    for(int i = 0; i < N; ++i) cout << arr[i].first << ' ' << arr[i].second << '\n';
}