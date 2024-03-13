#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    if(N == 1) cout << "*";
    else {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N/2 + N%2; ++j) cout << "* ";
            cout << '\n';
            for(int j = 0; j < N/2; ++j) cout << " *";
            cout << '\n';
        }
    }
}