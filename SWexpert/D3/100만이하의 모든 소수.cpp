#include<iostream>
using namespace std;
void getChe(int num) {
    int arr[1000000];
    int i = 2;
    // �Է¹��� �� ��ŭ �迭�� ��� �ʱ�ȭ �صд�
    for (i = 2; i <= num; i++) {
        arr[i] = i;
    }

    for (i = 2; i <= num; i++) {
        if (arr[i] == 0) // �̹� üũ�� ���� ����� Ȯ������ �ʴ´�
            continue;
        for (int j = i + i; j <= num; j += i) { // i�� ������ i�� ������� 0���� üũ
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





