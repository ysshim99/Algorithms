#include <bitset>

using namespace std;

int solution(int N) {
    return bitset<32>(N).count(); // 2진수로 변환한 N의 1의 개수를 반환
}