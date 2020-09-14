#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int T, N;
long long node[1000][2], costL2[1000][1000], weight,ans,answer;
double E;
bool visited[1000];

void func(int i, int j, int cnt) {
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
	long long restMinWeight = pow(10, 13);
	for (int k = 0; k < N; k++) {
		if (visited[k] == true) continue;
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
		cin >> N;
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
			}
		}
		answer = pow(10, 13);
		for (int i = 0; i < N; i++) {
			memset(visited, 0, sizeof(visited));
			ans = 0;
			func(i, i, 0);
			if (ans < answer) {
				answer = ans;
			}
		}
		cout << "#" << tc << " " << (long long)round(E * answer) << endl;
	}
	return 0;
}