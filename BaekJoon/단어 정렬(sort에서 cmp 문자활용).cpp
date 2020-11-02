#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
string str;
vector<string> vec;

bool cmp(const string& s1, const string& s2) {

	if (s1.size() == s2.size()) { //사이즈가 같으면, 사전순 앞으로. 
		return s1 < s2;
	}
	return s1.size() < s2.size();    //사이즈 다르면 작은게 앞으로. 

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end(),cmp);
	vec.erase(unique(vec.begin(), vec.end()),vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
	return 0;
}