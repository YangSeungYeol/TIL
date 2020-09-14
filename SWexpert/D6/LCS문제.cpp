#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int LCS[502][502] = { 0 };
        int N;
        cin >> N;
        string X;
        string Y;
        cin >> X >> Y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (X[i] == Y[j]) {
                    LCS[i + 1][j + 1] = LCS[i][j] + 1;
                }
                else {
                    LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]);
                }
            }
        }
        cout << fixed; 
        cout.precision(2);
        cout << "#" << tc << " " << (double)LCS[N][N] / (double)N * 100 << endl;
    }
    return 0;

}