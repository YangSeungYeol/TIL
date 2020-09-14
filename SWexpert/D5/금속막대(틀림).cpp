#include<iostream>
#include<vector>
using namespace std;

int test_case, T, N;
vector <pair<int, int>> vec;
pair <int, int> p;

int main(int argc, char** argv)
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			vec.push_back(p);
		}
		cout << "ÀÎÇ²" << endl;
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].first << " " << vec[i].second << " ";
		}
		cout << endl;

		for (int i = 0; i < vec.size()-1; i++) {
			for (int j = 0; j < vec.size(); j++) {
				if (j == i + 1 && vec[i].second == vec[j].first) continue;
				if (j != i + 1 && vec[i].second == vec[j].first) {
					cout <<  i + 1 <<" "<<vec[j].first<<" "<<vec[j].second<< endl;
					cout << j + 1 << endl;
					vec.insert(vec.begin() + i + 1, vec[j]);
					for (int k = 0; k < vec.size(); k++) {
						cout << vec[k].first << "," << vec[k].second << " ";
					}
					cout << endl;
					vec.erase(vec.begin() + j + 1);
					 
				 }
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i].first << " " << vec[i].second << " ";
		}
		 cout<< endl;
	}
	return 0;
}