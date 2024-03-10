#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 소수점 1자리 표시를 위한 설정
    cout << fixed;
    cout.precision(1);
        
    string grade;
    cin >> grade;
    
    double score;
    if(grade[0] == 'A') score = 4.0;
    else if(grade[0] == 'B') score = 3.0;
    else if(grade[0] == 'C') score = 2.0;
    else if(grade[0] == 'D') score = 1.0;
    else if(grade[0] == 'F') score = 0.0;
    
    if(grade[1] == '+') score += 0.3;
    else if(grade[1] == '-') score -= 0.3;
    
    cout << score;
}