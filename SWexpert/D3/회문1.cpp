#include <cstdio>
#include <iostream>
using namespace std;

int tc, N,totalCnt,rowCnt,colCnt ;
char arr[8][8];
string str;
string str1 = "";
string str2 = "";

int main(int argc, char** argv) {
    for (int tc = 1; tc <= 10; tc++) {
        scanf_s("%d", &N);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> arr[i][j];
            }
        }
        rowCnt = 0;
        colCnt = 0;
        totalCnt = 0;
        //�� ȸ���˻�
        for (int i = 0; i < 8; i++) {
            for (int start = 0; start < 8 - N+1; start++) {
                str = "";
                for (int j = start; j < start+N ; j++) {//N���ܾ���̷���� str
                    str = str + arr[i][j];
                }
                //N�� ¦���ϰ��
                if (N % 2 == 0) {
                    str1 = str.substr(0, N / 2);
                    str2 = str.substr(N / 2);
                    reverse(str2.begin(), str2.end());
                }
                //N�� Ȧ���ϰ��
                if (N % 2 == 1) {
                    str1 = str.substr(0, N / 2+1);
                    str2 = str.substr(N / 2);
                    reverse(str2.begin(), str2.end());
                }
                //str1�� str2 ��
                if (str1 == str2) {
                    rowCnt++;
                }
            }
        }
        //�� ȸ���˻�
        for (int i = 0; i < 8; i++) {
            for (int start = 0; start < 8 - N + 1; start++) {
                str = "";
                for (int j = start; j < start + N; j++) {//N���ܾ���̷���� str
                    str = str + arr[j][i];
                }
                //N�� ¦���ϰ��
                if (N % 2 == 0) {
                    str1 = str.substr(0, N / 2);
                    str2 = str.substr(N / 2);
                    reverse(str2.begin(), str2.end());
                }
                //N�� Ȧ���ϰ��
                if (N % 2 == 1) {
                    str1 = str.substr(0, N / 2 );
                    str2 = str.substr(N / 2+1 );
                    reverse(str2.begin(), str2.end());
                }
                //str1�� str2 ��
                if (str1 == str2) {
                    colCnt++;
                }
            }
        }
        totalCnt = rowCnt+colCnt;
        printf("#%d %d\n", tc, totalCnt);
    }
    return 0;
}