#include<iostream>
#include<memory.h>
using namespace std;

int tc, T, N, E, mins, back, dist[1000][1000], ans, minAns;
bool visited[1000];
int dis[1000];
int INF = 1000001;

void dijkstra(int start) {
	for (int i = 0; i < N; i++) {
		dis[i] = INF;
	}
	dis[start] = 0;
	for (int i = 0; i < N; i++) {
		mins = INF;
		for (int j = 0; j < N; j++) {
			if (visited[j] == 0 && (dis[j] < mins)) {
				back = j;
				mins = dis[j];
			}
		}
		visited[back] = true;
		for (int j = 0; j < N; j++) {
			if (dis[back] + dist[back][j] < dis[j]) {
				dis[j] = dis[back] + dist[back][j];
			}
		}
	}
}

int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		minAns = 1000000;
		memset(dist, 0, sizeof(dist));
		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> E;
				if (E != 0 || i == j) dist[i][j] = E;
				else dist[i][j] = INF;
			}
		}
		for (int i = 0; i < N; i++) {
			dijkstra(i);
			ans = 0;
			for (int k = 0; k < N; k++) ans += dis[k];
			if (ans < minAns) minAns = ans;
			memset(visited, 0, sizeof(visited));
		}
		cout << "#" << tc << " " << minAns << endl;
	}
	return 0;
}