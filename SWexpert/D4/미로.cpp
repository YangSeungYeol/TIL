#include<iostream>
#include<algorithm>
using namespace std;

int test_case, T,ans, startX, startY;
int miro[16][16];
bool visited[16][16];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int row,int col) {
	if (miro[row][col] == 1|| visited[row][col] == 1)
		return;
	if (miro[row][col] == 3) {
		ans = 1;
		return;
	}
	visited[row][col] = true;
	for (int i = 0; i < 4; i++) {
		dfs(row+dx[i], col+dy[i]);
	}
}
int main(int argc, char** argv)
{
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		ans = 0;
		memset(visited, 0, sizeof(visited));
		cin >> T;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf_s("%1d", &miro[i][j]);
				if (miro[i][j] == 2) {
					startX = i;
					startY = j;
				}
			}
		}
		dfs(startX, startY);
		cout << "#" << test_case << " "<<ans<< endl;
	}
	return 0;
}