#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    deque<int> DQ;
    for(int i = 1; i <= N; ++i) DQ.push_back(i);
    
    int cnt = 0;
    while(M--) {
        int num;
        cin >> num;
        
        int idx = find(DQ.begin(), DQ.end(), num) - DQ.begin();
        
        while(DQ.front() != num) {
            if(idx < DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            
            cnt++;
        }
        
        DQ.pop_front();
    }
    
    cout << cnt;
}