#include <bits/stdc++.h>
using namespace std;

/*
input을 입력으로 받으면 arr[input] + 1 한다.
출력할 때는 arr[input]의 값만큼 반복문 수행한다.
*/

int arr[10002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    while(N--) {
        int input;
        cin >> input;
        
        arr[input]++;
    }
    
    for(int i = 1; i <= 10000; ++i) {
        for(int j = 0; j < arr[i]; ++j) {
            cout << i << '\n';
        }
    }
}