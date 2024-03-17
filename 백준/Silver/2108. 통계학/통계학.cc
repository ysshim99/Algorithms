#include <bits/stdc++.h>
using namespace std;

int input[500002];
int arr1[8002]; // -4000 ~ 4000 이 나온 빈도수 저장
vector<int> v; // 서로 다른 최빈값 저장

int N; // N: 개수
double sum = 0;
int mode, modeCnt = 0; // mode: 최빈값, modeCnt: 최빈값 개수

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        input[i] = num;
        arr1[num+4000]++;
        sum += num;
    }

    sort(input, input+N);

    mode = *max_element(arr1, arr1+8001);

    for(int i = 0; i < 8002; ++i) {
        if(arr1[i] == mode) {
            v.push_back(i-4000);
            modeCnt++;
        }
    }

    cout << int(round(sum / N)) << '\n';
    cout << input[N/2] << '\n';
    if(modeCnt == 1) cout << v[0] << '\n';
    if(modeCnt > 1) cout << v[1] << '\n';
    cout << input[N-1] - input[0];
}