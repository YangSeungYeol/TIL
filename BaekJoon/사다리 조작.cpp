#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;

int N, M, H;
int row, col;
int ladder[31][11];



void dfs(int x, int y) {
	if (x + 1 > H || y + 1 > M || x - 1 < 0 || y - 1 < 0) {

		return;
	}
	if (ladder[x][y] == 0 && ladder[x][y + 1] == 0 && ladder[x][y - 1] == 0)
		dfs(x + 1, y);
	if (ladder[x][y] == 1)
		dfs(x, y - 1);
	if (ladder[x][y + 1] == 1)
		dfs(x, y + 1);
}


int main() {
	memset(ladder, 0, sizeof(ladder) + 1);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> row >> col;
		ladder[row][col] = 1;
	}

	for (int i = 0; i < H+1; i++) {
		for (int j = 0; j < M+1; j++) {
			cout << ladder[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}