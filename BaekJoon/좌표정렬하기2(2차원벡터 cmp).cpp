#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int, int>> coordGroup;
pair<int, int> coord;


bool cmp(const pair<int, int>& v1, const pair<int, int>& v2) {
	if (v1.second == v2.second) {
		return v1.first < v2.first;
	}
	return v1.second < v2.second;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coord.first >> coord.second;
		coordGroup.push_back(coord);
	}
	sort(coordGroup.begin(), coordGroup.end(),cmp);

	for (int i = 0; i < N; i++) {
		cout << coordGroup[i].first << " " << coordGroup[i].second << '\n';
	}
	return 0;
}