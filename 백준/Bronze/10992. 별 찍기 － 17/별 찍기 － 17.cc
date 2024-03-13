#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N;
    cin >> N;

    if(N == 1) {
        cout << '*';
    }
    else {
        for(int i = 0; i < N-1; ++i) cout << ' ';
        cout << "*\n";
        for(int i = 1; i < N-1; ++i) {
            for(int j = 0; j < N-1-i; ++j) cout << ' ';
            cout << '*';
            for(int j = 0; j < 2*i-1; ++j) cout << ' ';
            cout << "*\n";
        }
        for(int i = 0; i < 2*N-1; ++i) cout << '*';
    }
}