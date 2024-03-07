#include <bits/stdc++.h>
using namespace std;

int cmp(string a, string b) {
    if(a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    string arr[20001];
    for(int i = 0; i < N; ++i) 
        cin >> arr[i];
    
    sort(arr, arr+N, cmp);
    
    for(int i = 0; i < N; ++i) {
        if(arr[i] == arr[i-1]) continue;
        cout << arr[i] << '\n';
    }
}