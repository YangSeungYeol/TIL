#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int dp[502][502] = { 0 };
        int N;
        cin >> N;
        string X;
        string Y;
        cin >> X >> Y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (X[i] == Y[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else {
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        double sol = (double)dp[N][N] / (double)N * 100;
        printf("#%d %.2f\n", tc, sol);
    }
}
