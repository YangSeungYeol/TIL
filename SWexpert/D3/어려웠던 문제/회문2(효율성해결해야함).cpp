#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int tc, N,totalMaxLength;
char arr[100][100];
string str;

bool ispal(string str) {//회문판별
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
            break;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    for (int tc = 1; tc <= 10; tc++) {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
        totalMaxLength = 0;
        for (int N = 1; N <=100; N++) {
            //행 회문검사
            for (int i = 0; i < 100; i++) {
                for (int start = 0; start < 100 - N + 1; start++) {
                    str = "";
                    for (int j = start; j < start + N; j++) {//N개단어로이루어진 str
                        str = str + arr[i][j];
                    }

                    if (ispal(str)) {
                        if (str.length() > totalMaxLength) {
                            totalMaxLength = str.length();
                            break;
                        }
                    }
                }
            }
        
            //열 회문검사
            for (int i = 0; i < 100; i++) {
                for (int start = 0; start < 100 - N + 1; start++) {
                    str = "";
                    for (int j = start; j < start + N; j++) {//N개단어로이루어진 str
                        str = str + arr[j][i];
                    }
                    //str1과 str2 비교
                    if (ispal(str)) {
                        if (str.length() > totalMaxLength) {
                            totalMaxLength = str.length();
                            break;
                        }
                    }
                }
            }
        }
        printf("#%d %d\n", tc, totalMaxLength);
    }
    return 0;
}