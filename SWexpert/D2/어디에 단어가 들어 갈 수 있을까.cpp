/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int test_case;
    int T;
    int N;
    int K;
    int ans;
    int num;
    scanf_s("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf_s("%d", &N);
        scanf_s("%d", &K);
        int binaryArr[16][16];
        ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf_s("%d", &binaryArr[i][j]);
            }
        }
        for (int k = 0; k < N; k++) {
            num = 0;
            for (int l = 0; l < N; l++) {
                if (binaryArr[k][l] == 1) {
                    num += 1;
                }
                else {
                    num = 0;
                }
                if (l != N - 1 && num == K) {
                    if (binaryArr[k][l + 1] == 0) {
                        ans += 1;
                    }
                }
                if (l == N - 1 && num == K) {
                    ans += 1;
                }
            }
        }
        for (int k = 0; k < N; k++) {
            num = 0;
            for (int l = 0; l < N; l++) {
                if (binaryArr[l][k] == 1) {
                    num += 1;
                }
                else {
                    num = 0;
                }
                if (l != N - 1 && num == K) {
                    if (binaryArr[l + 1][k] == 0) {
                        ans += 1;
                    }
                }
                if (l == N - 1 && num == K) {
                    ans += 1;
                }
            }
        }
        printf_s("#%d %d\n", test_case, ans);
    }
    return 0;
}