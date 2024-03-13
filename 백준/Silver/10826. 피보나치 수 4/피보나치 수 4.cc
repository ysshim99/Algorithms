#include <bits/stdc++.h>
using namespace std;

string string_add(string x, string y) {
    int num, carry = 0;
    string result;
    
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    
    while(x.length() < y.length()) x += '0';
    while(y.length() < x.length()) y += '0';
    
    for(int i = 0; i < x.length(); ++i) {
        int sum = x[i]-'0' + y[i]-'0' + carry;
        num = sum % 10;
        result += to_string(num);
        carry = sum / 10;
    }
    if(carry) result += '1';
    
    reverse(result.begin(), result.end());
    return result;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    string arr[10002];
    arr[0] = '0';
    arr[1] = '1';
    
    for(int i = 2; i <= n; ++i) {
        arr[i] = string_add(arr[i-1], arr[i-2]);
    }
    
    cout << arr[n];
}