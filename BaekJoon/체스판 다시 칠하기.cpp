#include<iostream>

using namespace std;

int N, M;
char board[50][50];

int main() {
	int ans = 100;
	char wChess[8][8] = {
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'}
	};
	char bChess[8][8] = {
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'},
		{'B','W','B','W','B','W','B','W'},
		{'W','B','W','B','W','B','W','B'}
	};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {
			int wCnt=0,bCnt=0;
			for (int p = 0; p < 8; p++) {
				for(int q = 0; q < 8; q++){
					if (board[i + p][j + q] != wChess[p][q]) wCnt++;
					if (board[i + p][j + q] != bChess[p][q]) bCnt++;
				}
			}
			if (wCnt >= bCnt && ans > bCnt) ans = bCnt;
			if (bCnt >= wCnt && ans > wCnt) ans = wCnt;
		}
	}
	cout << ans << endl;
	return 0;
}