#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int height[9], total = 0;

    for(int i = 0; i < 9; ++i) {
        cin >> height[i];
        total += height[i];
    }

    sort(height, height + 9);
    
    for(int i = 0; i < 8; ++i) {
        for(int j = i+1; j < 9; ++j) {
            if(total - height[i] - height[j] == 100) {
                for(int k = 0; k < 9; ++k) {
                    if(k != i && k != j) {
                        cout << height[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }
}