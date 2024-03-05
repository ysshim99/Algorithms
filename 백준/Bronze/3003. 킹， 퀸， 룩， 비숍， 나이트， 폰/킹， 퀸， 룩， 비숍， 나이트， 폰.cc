#include <iostream>

using namespace std;

int main() {
    int arr1[] = { 1, 1, 2, 2, 2, 8 };
    int arr2[6];
    
    for(int i = 0; i < 6; ++i)
        cin >> arr2[i];
    
    for(int i = 0; i < 6; ++i)
        cout << arr1[i] - arr2[i] << " ";
}