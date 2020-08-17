#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
    int test_case, N, M,cnt;
    int jomangArr[255][1000];
    
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cnt = 0;
        cin >> N;
        for (int i = 0; i < N; i++) { //i가 열
            cin >> M;
            for (int j = 0; j <255; j++) { //j가 행
                if (j < M) {
                    jomangArr[254-j][i] = 1;
                }
                else {
                    jomangArr[254-j][i] = 0;
                }
            }
        }
        for (int i = 0; i < 255; i++) {
            for (int j = 2; j < N-2; j++) {
                if (jomangArr[i][j - 2] == 0 && jomangArr[i][j - 1]==0 && jomangArr[i][j] == 1 && jomangArr[i][j + 1] == 0 && jomangArr[i][j + 2] == 0) {
                    cnt++;
                }
            }
        }
        cout << "#" << test_case << " " << cnt << endl;
    }
    return 0;
}