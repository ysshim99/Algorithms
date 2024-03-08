#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K;
    cin >> K;
    
    stack<int> S;
    while(K--) {
        int input;
        cin >> input;
        
        if(input) S.push(input);
        else S.pop();
    }
    
    int sum = 0;
    while(!S.empty()) {
        sum += S.top();
        S.pop();
    }
    
    cout << sum;
}