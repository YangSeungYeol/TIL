#include<iostream>
#include<time.h>
using namespace std;

int sudoku[9][9];
int pos[2],garoPos[2],seroPos[2],zeroCnt;

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)zeroCnt++;
		}
	}
}

void rowOrColCheck() {
	for (int i = 0; i < 9; i++) {
		int garoCnt = 0, seroCnt = 0, garoSum = 0,seroSum = 0;
		for (int j = 0; j < 9; j++) {
			garoSum += sudoku[i][j];
			seroSum += sudoku[j][i];
			if (sudoku[i][j] == 0) {
				garoPos[0] = i;
				garoPos[1] = j;
				garoCnt++;
			}
			if (sudoku[j][i] == 0) {
				seroPos[0] = j;
				seroPos[1] = i;
				seroCnt++;
			}
		}
		if (garoCnt == 1) {
			sudoku[garoPos[0]][garoPos[1]] = 45 - garoSum;
			zeroCnt--;
		}
		if ((garoPos[0]!=seroPos[0]||garoPos[1]!=seroPos[1])&&seroCnt == 1) {
			sudoku[seroPos[0]][seroPos[1]] = 45 - seroSum;
			zeroCnt--;
		}
	}
}

void squareCheck(int posX,int posY) {
	int cnt = 0;
	int sum = 0;
	for (int i = posX; i < posX+3; i++) {
		for (int j = posY; j < posY+3; j++) {
			sum += sudoku[i][j];
			if (sudoku[i][j] == 0) {
				pos[0] = i;
				pos[1] = j;
				cnt++;
			}
		}
	}
	if (cnt == 1) {
		sudoku[pos[0]][pos[1]] = 45 - sum;
		zeroCnt--;
	}
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << " ";
		}
		cout << '\n';
	}
}

void solve() {
	while (zeroCnt) {
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				squareCheck(i, j);
			}
		}
		if (zeroCnt == 0)break;
		rowOrColCheck();
	}
}

int main() {
	int start, end;
	start = clock();
	input();
	solve();
	print();
	end = clock();
	cout << end - start << endl;
	return 0;
}