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

    queue< pair<int, int> > q; // �̿��� ť, (x,y) -> (��, ��)
    q.push(make_pair(x, y)); // pair�� ���� queue�� �ֽ��ϴ�.

    // ó�� x,y�� �湮 �߱⶧����
    visited[x][y] = true;

    while (!q.empty()) {

        // ť�� ���� ���Ҹ� ������
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // �ش� ��ġ�� �ֺ��� Ȯ��
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // ������ ����� �ʰ�
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                // �湮���� �ʾҴٸ� -> �湮
                if (!visited[nx][ny]||sumCost[nx][ny]>sumCost[x][y]+map[nx][ny]) {
                    sumCost[nx][ny] = sumCost[x][y] + map[nx][ny];
                    visited[nx][ny] = true;
                    // ť�� ���� nx,ny�� �߰�
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