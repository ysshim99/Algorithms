#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, string> > member(N);
    
    for(int i = 0; i < N; ++i)
        cin >> member[i].first >> member[i].second;
    
    stable_sort(member.begin(), member.end(), cmp);
    
    for(int i = 0; i < N; ++i) 
        cout << member[i].first << ' ' << member[i].second << '\n';
}