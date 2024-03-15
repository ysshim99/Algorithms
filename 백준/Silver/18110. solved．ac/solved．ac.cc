#include <bits/stdc++.h>
using namespace std;

int n;
int level[300002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	if(n == 0) {
		cout << 0;
		return 0;
	}

	for(int i = 0; i < n; ++i) cin >> level[i];
	sort(level, level+n);

	int num = round(n*0.15);
	double sum = 0;
	
	for(int i = num; i <= n-1-num; ++i) {
		sum += level[i];
	}

	cout << round(sum / (n-2*num));
}