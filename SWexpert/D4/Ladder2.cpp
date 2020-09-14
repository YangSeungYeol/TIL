#include<iostream>
using namespace std;
int tc, T, x, y, ladder[100][100],totalCnt,minCnt,ans,templad[100][100];

bool visited[100][100];

void dfs(int x, int y, int cnt) {
	if (x == 99) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cout << ladder[i][j] << " ";

			}
			cout << endl;
		}
		cout << endl;
		totalCnt = cnt;
		return;
	}
	visited[x][y] = true;
	if (y!=99&&ladder[x][y + 1] == 1&&visited[x][y+1]==false) {
		ladder[x][y + 1] = 9;
	
		dfs(x, y + 1, cnt + 1);
	}
	else if (y!=0&&ladder[x][y - 1] == 1 && visited[x][y - 1] == false) {
		ladder[x][y - 1] = 9;
		
		dfs(x, y - 1, cnt + 1);
	}
	else {
		
		ladder[x + 1][y] = 9;
		dfs(x + 1, y, cnt + 1);
	
	}
	visited[x][y] = false;
}

int main(int argc, char** argv)
{
	for (tc = 1; tc <= 1; ++tc)
	{
		minCnt = 10000;
		cin >> T;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> ladder[i][j];
				templad[i][j] = ladder[i][j];
			}
		}
		for (int n = 0; n <100; n++) {
			if (ladder[0][n] == 0)continue;
			memset(visited, 0, sizeof(visited));
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					ladder[i][j] = templad[i][j];
				}
			}
			dfs(0, n, 0);
			cout << endl;
			if (totalCnt < minCnt) {
				minCnt = totalCnt;
				ans = n;
				cout <<"ans "<<ans <<" totalCnt "<<totalCnt<< endl;
			}
			
		}
		cout << "#" << T << " " << ans << endl;
	}
	return 0;
}