#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int num1 = N/5;
    int num2;
    
    while(num1 >= 0) {
        if((N - 5*num1) % 3 == 0) {
            num2 = (N - 5*num1)/3;
            cout << num1 + num2;
            return 0;
        }
        num1--;
    }
    
    cout << -1;
}