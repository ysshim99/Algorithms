#include <bits/stdc++.h>
using namespace std;

int arr[1000002];
int tmp[1000002];

int N;

// arr[start:mid], arr[mid:end]는 이미 정렬되어 있는 상태
void merge(int start, int end) {
  int mid = (start + end) / 2;
  int idxL = start;
  int idxR = mid;
  
  for (int i = start; i < end; ++i) {
    if (idxL == mid) tmp[i] = arr[idxR++];
    else if (idxR == end) tmp[i] = arr[idxL++];
    else if (arr[idxL] <= arr[idxR]) tmp[i] = arr[idxL++];
    else tmp[i] = arr[idxR++];
  } 
  
  for (int i = start; i < end; ++i) arr[i] = tmp[i]; 
}

// arr[start:end]를 정렬
void merge_sort(int start, int end) {
  if (start+1 == end) return;
  
  int mid = (start + end) / 2;
  
  merge_sort(start, mid);
  merge_sort(mid, end);
  merge(start, end);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  
  merge_sort(0, N);
  
  for (int i = 0; i < N; ++i) cout << arr[i] << '\n';
}
