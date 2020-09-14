#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int T, N;
long long node[1000][2], costL2[1000][1000], weight, ans, answer;6
double E;
bool visited[1000];

void prim(int i, int j, int cnt) {
	if (cnt >= N-1) {
		return;
	}
	/*cout << "i " << i << endl;
	cout << "j " << j << endl;
	cout << cnt << endl;
	for (int i = 0; i < N; i++) {
		cout<<"visi  "<<visited[i] << endl;
	}*/
	int nexti = 0, nextj = 0;
	visited[i] = true;
	long long minWeight = pow(10, 15);
	for (int k = 0; k < N; k++) {
		if (visited[k] == true) {
			for (int l = 0; l < N; l++) {
				if (k == l || visited[l] == true)continue;
				if (costL2[k][l] < minWeight) {
					minWeight = costL2[k][l];
					nexti = l;
					nextj = k;
				}
			}
		}
	}
	//cout <<"minWeight"<< minWeight << endl;
	ans += minWeight;
	/*cout << "nexti " << nexti << endl;
	cout << "nextj" << nextj << endl;*/
	prim(nexti, nextj, cnt + 1);
}

int main(int argc, char** argv)
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{	
		memset(visited, 0, sizeof(visited));
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
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << costL2[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		ans = 0;
		prim(0,0,0);
		cout << "#" << tc << " " << (long long)round(E * ans) << endl;
	}
	return 0;
}