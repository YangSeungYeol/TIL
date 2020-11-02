#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,ranking;
vector<pair<int, int>> vec;
pair<int, int> dungchi;

int main() {
	vector <int> ans;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dungchi.first >> dungchi.second;
		vec.push_back(dungchi);
	}

	for (int i = 0; i < N; i++) {
		ranking = 0;
		for (int j = 0; j < N; j++) {
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
				ranking++;
			}
		}
		printf_s("%d ", ranking + 1);
	}

	return 0;
}