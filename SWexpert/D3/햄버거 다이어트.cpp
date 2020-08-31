#include<iostream>
#include<vector>
using namespace std;

int T, N, L, ans;
vector<pair<int, int>> info;
pair <int, int> p;

void func(int i ,int sumScore,int sumCal) {
	if (i == N) {
		return;
	}
	if (sumCal + info[i].second < L&& sumScore + info[i].first>ans){
		ans = sumScore + info[i].first;
	}
	func(i+1,sumScore,sumCal);
	func(i+1,sumScore+info[i].first,sumCal+info[i].second);
	
}

int main(int argc, char** argv)
{
	int test_case;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		info.clear();
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> p.first;
			cin >> p.second;
			info.push_back(p);
		}
		ans = 0;
		func(0,0, 0);

		cout << "#" << test_case << " " << ans << endl;

	}
	return 0;
}