#include<iostream>
using namespace std;
void getChe(int num) {
    int arr[1000000];
    int i = 2;
    // 입력받은 수 만큼 배열에 모두 초기화 해둔다
    for (i = 2; i <= num; i++) {
        arr[i] = i;
    }

    for (i = 2; i <= num; i++) {
        if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
            continue;
        for (int j = i + i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            arr[j] = 0;
        }
    }
    // print
    for (i = 2; i <= num; i++) {
        if (arr[i] != 0) cout << arr[i] << " ";
    }
}
int main(void) {
    getChe(1000000);
    return 0;
}





