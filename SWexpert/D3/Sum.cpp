#include <iostream>
using namespace std;

int tc,T, N,sum,maxSum;
int arr[100][100];

int main(int argc, char** argv) {
    for (int tc = 1; tc <= 10; tc++) {
        cin >> T;
        maxSum = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
        //가로합
        for (int i = 0; i < 100; i++) {
            sum = 0;
            for (int j = 0; j < 100; j++) {
                sum += arr[i][j];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        //세로합
        for (int i = 0; i < 100; i++) {
            sum = 0;
            for (int j = 0; j < 100; j++) {
                sum += arr[j][i];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
        //좌상우하대각선합
        sum = 0;
        for (int i = 0; i < 100; i++) {
                sum += arr[i][i];
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
        //우상좌하대각선합
        sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += arr[i][99-i];
        }
        if (sum > maxSum) {
            maxSum = sum;
        }
        printf("#%d %d\n", T, maxSum);
    }
    return 0;
}