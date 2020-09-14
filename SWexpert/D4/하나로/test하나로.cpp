#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, islandNum;
int start[1000][2];
long long node[1000][2];
long long costL2[1000][1000]; //1행은 1번째섬에 연결하는 코스트
double E, ans;
long long allWeight, minWeight, weight;
bool visited[1000];

void func(int i, int j,int cnt) {
	if (cnt >= N) {
		return;
	}
	visited[i] = true;
	visited[j] = true;
	int nexti = 0;
	int nextj = 0;
	if (cnt != 0) {
		ans += costL2[i][j];
	}
	long long restMinWeight = pow(10,13);
	for (int k = 0; k < N; k++) {
		if (visited[k]==true) continue;
		if (costL2[j][k] < restMinWeight) {
			restMinWeight = costL2[j][k];
			nexti = j;
			nextj = k;	
		}
	}
	func(nexti, nextj, cnt + 1);
}

int main(int argc, char** argv)
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		minWeight = pow(10,13);
		ans = 0;
		memset(visited, 0, sizeof(visited));
		cin >> N;//N은 섬의개수
		for (int i = 0; i < N; i++) {
			cin >> node[i][0];
		}
		for (int i = 0; i < N; i++) {
			cin >> node[i][1];
		}
		cin >> E;
		for (int i = 0; i < N; i++) {
			int n = 0;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				weight = (pow((node[i][0] - node[j][0]), 2) + pow((node[i][1] - node[j][1]), 2));
				costL2[i][j] = weight;
				costL2[j][i] = weight;
				if (weight < minWeight) {
					minWeight = weight;
				}
			}
		}
		func(0,0,0);
		cout << "#" << tc << " " << (long long)round(E * ans) << endl;
	}
	return 0;
}