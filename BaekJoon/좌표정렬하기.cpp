#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <pair<int, int>> coordGroup;
pair<int, int> coord;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coord.first >> coord.second;
		coordGroup.push_back(coord);
	}
	sort(coordGroup.begin(), coordGroup.end());

	for (int i = 0; i < N; i++) {
		cout << coordGroup[i].first << " " << coordGroup[i].second << '\n';
	}
	return 0;
}