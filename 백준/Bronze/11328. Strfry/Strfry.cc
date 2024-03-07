#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        int alpha[26] = {0, };
        
        string a, b;
        cin >> a >> b;
        
        for(auto c : a) alpha[c - 'a']++;
        for(auto c : b) alpha[c - 'a']--;
        
        bool isPossible = true;
        
        for(auto i : alpha)
            if(i != 0) isPossible = false;
        
        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }    
}