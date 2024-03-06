#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    string s = to_string(num1 * num2 * num3);
    int num[10] = {0, };

    for(int i = 0; i < s.length(); ++i)
        num[s[i] - '0']++;
    

    for(int i = 0; i < 10; ++i)
        cout << num[i] << " ";
}