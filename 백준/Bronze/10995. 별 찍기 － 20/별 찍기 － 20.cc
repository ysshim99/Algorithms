#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N;
    cin >> N;

    for(int i = 0; i < N; ++i) {
        if(i % 2 == 0) {
            for(int j = 0; j < N; ++j) cout << "* ";
            cout << '\n';
        }
        else {
            for(int j = 0; j < N; ++j) cout << " *";
            cout << '\n';
        }
    }
}