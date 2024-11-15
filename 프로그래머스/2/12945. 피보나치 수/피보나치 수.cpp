#include <vector>

using namespace std;

// 피보나치 수열의 n번째 값을 계산하는 함수
int solution(int n) {
    vector<int> fib = {0, 1}; // fib(0) = 0, fib(1) = 1
    
    for (int i = 2; i <= n; ++i) {
        fib.push_back((fib[i - 1] + fib[i - 2]) % 1234567);
    }
    
    return fib[n];
}