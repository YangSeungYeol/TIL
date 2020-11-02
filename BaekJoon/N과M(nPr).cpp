#include<iostream>

using namespace std;

int N, M, pArr[9];
bool check[9];

void permutation(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << pArr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            check[i] = true;
            pArr[depth] = i+1;
            permutation(depth + 1);
            check[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    permutation(0);
	return 0;
}