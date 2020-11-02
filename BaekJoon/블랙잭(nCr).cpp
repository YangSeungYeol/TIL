#include<iostream>
using namespace std;

int N, M, card[100],sum,answer,cArr[3];

void combination(int depth, int next) {
    if (depth == 3) {
        sum = cArr[0]+cArr[1]+cArr[2];
        if (sum <= M&&sum>answer) {
            answer = sum;
        }
        return;
    }
    for (int i = next; i < N; i++) {
        cArr[depth] = card[i];
        combination(depth + 1, i + 1);
    }
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
    combination(0, 0);
	cout << answer << endl;
	return 0;
}