#include<iostream>
#include<vector>
using namespace std;

int tc, T, N;
vector <pair<int, int>> vec;
vector <pair<int, int>> ans;
pair <int, int> p;

int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		vec.clear();
		ans.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			vec.push_back(p);
		}
		while (!vec.empty()) {
			if (ans.empty()) {
				ans.push_back(vec[0]);
				vec.erase(vec.begin());
			}
			for (int i = 0; i < ans.size(); i++) {
				for (int j = 0; j < vec.size(); j++) {
					if (ans[i].second == vec[j].first) {
						ans.push_back(vec[j]);
						vec.erase(vec.begin() + j);
						continue;
					}
					if (ans[i].first == vec[j].second) {
						ans.insert(ans.begin(), vec[j]);
						vec.erase(vec.begin() + j);
						continue;
					}
				}
			}
		}
		cout << "#" << tc << " ";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << " ";
		}
		 cout<< endl;
	}
	return 0;
}