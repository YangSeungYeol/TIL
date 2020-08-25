#include <iostream>
#include<cmath>
using namespace std;
int T, N, ans, E;
string X;
int main(int argc, char** argv) {
    scanf_s("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> X;
        ans = 0;
        for (int i = 0; i < X.size(); i++) {
            E = pow(N, X.size() - i - 1);
            ans += (X.at(i) - '0')%(N-1);
            //ans += ((X.at(i) - '0') * E)%(N-1);
        }
        cout << ans << endl;
        ans = ans % (N - 1);
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}