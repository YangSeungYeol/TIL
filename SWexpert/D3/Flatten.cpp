#include <iostream>
#define MAX 10
using namespace std;

int main(int argc, char** argv) {
    int test_case,N,M,diff,maxRow,minRow,maxCol,minCol;
    for (test_case = 1; test_case <= 10; test_case++) {
        cin >> N;//dumpȽ��
        int boxArr[100][100] = { 0 };
        for (int i = 0; i < 100; i++) { //���� ���ΰ� 1 ���°� 0�� 2�����迭 �����
            cin >> M;
            for (int j = M-1; j >= 0; j--) {
                boxArr[99-j][i] = 1;
            }
        }
        for (int k = 0; k < N+1; k++) {//Nȸ dump�ϴ� �ݺ���
            bool box_exist = false;
            bool box_none = false;
            for (int i = 0; i < 100; i++) {// ���� ���� ���� �ִ� ������ ��� ã��
                if (box_exist == true) {
                    break;
                }
                for (int j = 0; j < 100; j++) {
                    if (boxArr[i][j] == 1) {
                        maxRow = i;
                        maxCol = j;
                        box_exist = true;
                        break;
                    }
                }
            }
            for (int i = 99; i >= 0; i--) {// ���� ���� ���� �ִ� �� ��� ã��
                if (box_none == true) {
                    break;
                }
                for (int j = 0; j < 100; j++) {
                    if (boxArr[i][j] == 0) {
                        minRow = i;
                        minCol = j;
                        box_none = true;
                        break;
                    }
                }
            }
            if (k != N) {
                swap(boxArr[maxRow][maxCol], boxArr[minRow][minCol]);
            }
            else{
                diff = minRow - maxRow + 1;
            }
        }

        cout << "#" << test_case << " "<< diff  << endl;
    }

}