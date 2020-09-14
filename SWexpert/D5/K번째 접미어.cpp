#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int test_case, T, K;
vector <string> vec;

int main(int argc, char** argv)
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> K;
		string str = "";
		string tempStr = "";
		cin >> str;
		for (int i = 0; i <str.size(); i++) {
			tempStr = str.substr(i);
			vec.push_back(tempStr);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		if (vec.size() < K) {
			cout << "#" << test_case << " none" << endl;
		}
		else {
			cout << "#" << test_case << " " << vec[K - 1] << endl;
		}
	}
	return 0;
}