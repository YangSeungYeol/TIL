#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, islandNum;
int start[1000][2];
long long node[1000][2];
double costL2[1000][1000]; //1행은 1번째섬에 연결하는 코스트
double E,ans;
long long allWeight,minWeight,weight;
//vector<long long> isVisit;
//bool isVisitArr[1000];
//distance[0]은 첫번째 섬과 두번째 섬의거리의 제곱
int main(int argc, char** argv)
{
	
	cin >> T;
	
	for (int tc = 1; tc <= T; ++tc)
	{
		int visitedCnt = 0;
		//isVisit.clear();
		/*for (int i = 0; i < 1000; i++) {
			isVisitArr[i] = false;
		}*/
		minWeight = -1;
		allWeight = 0;
		cin >> N;//N은 섬의개수
		for (int i = 0; i < N; i++) {
			cin >> node[i][0];
		}
		for (int i = 0; i < N; i++) {
			cin >> node[i][1];
		}
		cin >> E;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				weight = (pow((node[i][0] - node[j][0]), 2) + pow((node[i][1] - node[j][1]), 2));
				costL2[i][j] = weight;
				costL2[j][i] = weight;
				cout << weight << endl;
				int n;
				if (minWeight == -1||weight < minWeight) {
					memset(start,0, sizeof(start));
					
					n = 0;//start배열이 초기화안되면 문제있어.
					minWeight = weight;
					start[n][0] = i;
					start[n][1] = j;
					n++;
				}else if (minWeight == weight) {
					start[n][0] = i;
					start[n][1] = j;
					n++;
				}
			}
		}
		//최소가중치인 곳 -> 즉, start점으로 할수있는점 체크
		for (int i = 0; i < sizeof(start); i++) {
			while (visitedCnt < N) {
				ans += costL2[start[i][0]][start[i][1]];
				costL2[start[i][0]][start[i][1]] = -1;
				costL2[start[i][1]][start[i][0]] = -1;
				double restMinWeight = -1;
				int nexti, nextj;
				for (int j = 0; j < N; j++) {
					if (costL2[start[i][1]][j] == -1) continue;
					if (costL2[start[i][1]][j] < restMinWeight || restMinWeight == -1) {
						restMinWeight = costL2[start[i][1]][j];
						nexti = start[i][1];
						nextj = j;
						memset(start, 0, sizeof(start));
						start[nexti][nextj] = 
					}
				}
				visitedCnt++;
			}
		}
		





		//isVisit.push_back(0);
		//isVisitArr[0] = true;
		//while (isVisit.size() < N) {
		//	int next = 0;
		//	long long minWeight = -1;
		//	for (auto now : isVisit) {
		//		for (int i = 0; i < N; i++) {
		//			if (i == now) continue;
		//			if (isVisitArr[i]) continue;
		//			if (minWeight == -1 || costL2[now][i] < minWeight) {
		//				minWeight = costL2[now][i];
		//				next = i;
		//			}
		//		}
		//	}
		//	allWeight += minWeight;
		//	//cout << "MIN : " << minWeight << " , ALL : " << allWeight << endl;
		//	isVisitArr[next] = true;
		//	isVisit.push_back(next);
		//}

		cout << "#" << tc << " " << (long long)round(E * allWeight) << endl;
	}
	return 0;
}