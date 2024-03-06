#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string init;
    cin >> init;
    
    list<char> L;
    for(auto c : init) L.push_back(c);
    
    auto cursor = L.end();
    
    int M;
    cin >> M;
    
    for(int i = 0; i < M; ++i) {
        char c;
        cin >> c;
        
        if(c == 'L') {
            if(cursor != L.begin()) cursor--;
        }
        else if(c == 'D') {
            if(cursor != L.end()) cursor++;
        }
        else if(c == 'B') {
            if(cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
        else {
            char input;
            cin >> input;
            
            L.insert(cursor, input);
        }
    }
    
    for(auto c : L) cout << c;
}