#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int, string>>>vec;
pair<int, pair<int, string>>info;
int N;

bool cmp(const pair<int,pair<int,string>> &p1, const pair<int, pair<int,string>> &p2) {
	if (p1.second.first == p2.second.first) {
		return p1.first < p2.first;
	}
	return p1.second.first < p2.second.first;
}


int main() {
	int age;
	string name;

	cin >> N;
	for (int i = 0; i < N; i++) {
		info.first = i;
		cin >> info.second.first >> info.second.second;
		vec.push_back(info);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].second.first << " " << vec[i].second.second << '\n';
	}

	return 0;
}