#include <iostream>
 
using namespace std;
 
int main() {
    int value;
    int max = -1, idx;
    
    for(int i = 0; i < 9; ++i) {
        cin >> value;
        
        if(value > max) {
            max = value;
            idx = i;
        }
    }
    
    cout << max << '\n' << idx + 1;
}