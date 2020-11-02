#include<iostream>

using namespace std;

int pipeArr[16][16];
int ans,N;
int dir[3][2] = { {0,1},{1,0},{1,1} };
void dfs(int x,int y,int status) {
	if (x == N-1&&y ==N-1) {
		ans += 1;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((i==0 && status == 1) || (i==1 && status == 0))continue;
		int nextX = x + dir[i][0];
		int nextY = y + dir[i][1];
		if (nextX >= N || nextY >= N || pipeArr[nextX][nextY] == 1)
			continue;
		if (i == 2 && (pipeArr[x][y + 1] == 1 || pipeArr[x + 1][y] == 1))
			continue;
		dfs(nextX, nextY, i);
	}
}


int main() {
	ans = 0;
	cin >> N;
	memset(pipeArr, 0, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pipeArr[i][j];
		}
	}
	dfs(0,1,0);


	cout << ans << endl;
	return 0;
}