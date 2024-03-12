#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, V;
    cin >> A >> B >> V;

    int days = 1 + (V-A)/(A-B);

    if((V-A)%(A-B) != 0) days++;
    
    if(A >= V) cout << 1;
    else cout << days;
}