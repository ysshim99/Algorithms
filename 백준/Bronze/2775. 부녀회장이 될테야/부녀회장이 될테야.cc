#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    int apt[16][16];
    for(int i = 1; i <= 14; ++i)
        apt[0][i] = i;

    while(T--) {
        int k, n;
        cin >> k >> n;

        for(int i = 1; i <= k; ++i) {
            int sum = 0;
            for(int j = 1; j <= n; ++j) {
                sum += apt[i-1][j];
                apt[i][j] = sum;
            }
        }

        cout << apt[k][n] << '\n';
    }
}