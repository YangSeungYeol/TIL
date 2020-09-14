#include<iostream>
#include<memory.h>
using namespace std;

int tc, T, N, E, dist[1000][1000];
bool visited[1000];
int INF = 1000001;

int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> E;
				if (E != 0 || i == j) dist[i][j] = E;
				else dist[i][j] = INF;
			}
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
		int mins = 100000;
		for (int n = 0; n < N; n++) {
			int box = 0;
			for (int m = 0; m < N; m++) {
				if (n != m)
					box += dist[n][m];
			}
			if (mins > box)
				mins = box;
		}
		cout << "#" << tc << " " << mins << endl;
	}
	return 0;
}