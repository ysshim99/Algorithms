#include <iostream>

using namespace std;

/*
    *     (5-1, 1+0*2)
   ***    (5-2, 1+1*2)
  *****   (5-3, 1+2*2)
 *******  (5-4, 1+3*2)
********* (5-5, 1+4*2)  => (N-i-1, 1+i*2)꼴
 *******  (1, 1+3*2)    => (i+1, 1+(N-2-i)*2) 꼴
  *****   (2, 1+2*2)
   ***    (3, 1+1*2)
    *     (4, 1+0*2)
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N-i-1; ++j) cout << ' ';
        for(int j = 0; j < 1+i*2; ++j) cout << '*';
        cout << '\n';
    }
    
    for(int i = 0; i < N-1; ++i) {
        for(int j = 0; j < i+1; ++j) cout << ' ';
        for(int j = 0; j < 1+(N-2-i)*2; ++j) cout << '*';
        cout << '\n';
    }
}