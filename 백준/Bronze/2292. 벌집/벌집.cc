#include <bits/stdc++.h>
using namespace std;

/*
육각형 번호
1      1  = 1 + 0*6  => n = 1
2-7,   7  = 1 + 1*6  => n = 2
8-19,  19 = 1 + 3*6  => n = 3
20-37, 37 = 1 + 6*6  => n = 4
38-61, 61 = 1 + 10*6 => n = 5

일반화하면 1 + 3(n-1)(n) = f(n)
즉, f(i-1) < N <= f(i) 이면 최소 i 개의 방을 지나간다.
*/

int honeycomb(int n) {
    return 1 + 3*(n-1)*n;
}

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int N;
    cin >> N;

    int num = 1;
    while(honeycomb(num) < N) {
        num++;
    }

    cout << num;
}