#include <bits/stdc++.h>
using namespace std;

int M, N;

bool isPrime(int n) {
	if(n == 1) return false;
	for(int i = 2; i*i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	for(int i = M; i <= N; ++i) {
		if(isPrime(i)) cout << i << '\n';
	}
}