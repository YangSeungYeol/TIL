#include <cstdio>

using namespace std;

int tc, T, N, start,cnt, upperRevenue,underRevenue,totalRevenue;
int farmArr[49][49];



int main(int argc, char** argv) {
    scanf_s("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf_s("%d", &N);
        for (int i = 0; i < N; i++) {//농장배열 input
            for (int j = 0; j < N; j++) {
                scanf_s("%1d", &farmArr[i][j]);
            }
        }
        upperRevenue = 0;
        underRevenue = 0;
        start = N/2;
        cnt = 1;
        for (int row = 0; row < N / 2; row++) {//위쪽 삼각형 값들 추출
            for (int col = start; col < start+cnt; col++) {
                upperRevenue += farmArr[row][col];
            }
            start--;
            cnt+=2;
        }
        start = 0;
        cnt = N;
        for (int row = N/2; row <N; row++) {//아랫쪽 삼각형 값들 추출
            for (int col = start; col < start+cnt; col++) {
                underRevenue += farmArr[row][col];
            }
            start++;
            cnt -= 2;
        }
        totalRevenue = upperRevenue + underRevenue;
        printf("#%d %d\n", tc, totalRevenue);
    }
    return 0;
}