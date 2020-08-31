#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arrVC[100][2];
vector <pair<int,int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, K, V, C,cnt;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> N >> K; //K는 가방의 부피
		for (int i = 0; i < N; i++) {
			cin >> V; //V는 물건의 부피
			cin >> C; //C는 물건의 가치
			vec.push_back({ V,C });
		}
		//가치가 큰순서로 정렬
		sort(vec.begin(), vec.end(),cmp);
		reverse(vec.begin(), vec.end());

		for (int i = 0; i < N; i++) {
			cout << vec[i].first<<" "<<vec[i].second << endl;
		}
		//K부피에 담을 수 있는 최대 가치
		//가치순으로 정렬. arrVC의 1열의 값을 더해서 5이하로 넣을 수 있는 모든 경우를 구하여 백터에 저장하고 가장큰값추출
		int currentV = 0;
		int currentC = 0;
		for (int i = 0; i < N; i++) {
			if (currentV < K){
				currentV += vec[i].first;
				currentC += vec[i].second;
			}

		}

		
	}
	return 0;
}