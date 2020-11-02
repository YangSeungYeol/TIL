#include<iostream>

using namespace std;

int N, M, cArr[9];
bool check[9];

void combination(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << cArr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        cArr[depth] = i + 1;
        combination(depth + 1);
    }
}

int main() {
    cin >> N >> M;
    combination(0);
    return 0;
}
