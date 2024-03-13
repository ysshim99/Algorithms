#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int cnt = 0, num = 0;
    
    while(cnt != N) {
        num++;
        if(to_string(num).find("666") != string::npos) cnt++;
    }
    
    cout << num;
}