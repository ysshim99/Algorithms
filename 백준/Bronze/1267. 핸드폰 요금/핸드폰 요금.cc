#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int Y = 0, M = 0;
    for(int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        
        Y += (input / 30 + 1) * 10;
        M += (input / 60 + 1) * 15;
    }
    
    if(Y > M) {
        cout << "M " << M;
    }
    else if(Y < M) {
        cout << "Y " << Y;
    }
    else {
        cout << "Y M " << Y;
    }
}