#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;

int tc, T, N;
int map[100][100];
bool visited[100][100];
int sumCost[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs(int x, int y) {

    queue< pair<int, int> > q; // 이용할 큐, (x,y) -> (행, 열)
    q.push(make_pair(x, y)); // pair를 만들어서 queue에 넣습니다.

    // 처음 x,y를 방문 했기때문에
    visited[x][y] = true;

    while (!q.empty()) {

        // 큐의 현재 원소를 꺼내기
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 지도를 벗어나지 않고
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                // 방문하지 않았다면 -> 방문
                if (!visited[nx][ny]||sumCost[nx][ny]>sumCost[x][y]+map[nx][ny]) {
                    sumCost[nx][ny] = sumCost[x][y] + map[nx][ny];
                    visited[nx][ny] = true;
                    // 큐에 현재 nx,ny를 추가
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
        memset(sumCost, 0, sizeof(sumCost));
        memset(visited, false, sizeof(visited));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf_s("%1d", &map[i][j]);
			}
		}
        bfs(0, 0);
		cout << "#" << tc <<" "<< sumCost[N-1][N-1] << endl;
	}
	return 0;
}