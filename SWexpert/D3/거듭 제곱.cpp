#include <iostream>
using namespace std;
int T, N, M;
int f(int N, int M) {
    if (M == 0) {
        return 1;
    }
    return N * f(N, M - 1);
}
int main(int argc, char** argv) {
    for (int tc = 1; tc <= 10; tc++) {
        scanf_s("%d\n %d %d", &T, &N, &M);
        printf("#%d %d\n", T, f(N, M));
    }
    return 0;
}