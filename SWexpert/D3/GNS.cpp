#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc, T,E, N;
char S;
string str;
vector <pair<string, int>> inputVec;
pair<string, int>v;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{	
		inputVec.clear();
		cin >> S >> E >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			v.first = str;
			inputVec.push_back(v);
		}
		for (int i = 0; i < N; i++) {
			if (inputVec[i].first == "ZRO") {
				inputVec[i].second = 0;
			}
			else if (inputVec[i].first == "ONE") {
				inputVec[i].second = 1;
			}
			else if (inputVec[i].first == "TWO") {
				inputVec[i].second = 2;
			}
			else if (inputVec[i].first == "THR") {
				inputVec[i].second = 3;
			}
			else if (inputVec[i].first == "FOR") {
				inputVec[i].second = 4;
			}
			else if (inputVec[i].first == "FIV") {
				inputVec[i].second = 5;
			}
			else if (inputVec[i].first == "SIX") {
				inputVec[i].second = 6;
			}
			else if (inputVec[i].first == "SVN") {
				inputVec[i].second = 7;
			}
			else if (inputVec[i].first == "EGT") {
				inputVec[i].second = 8;
			}
			else if (inputVec[i].first == "NIN") {
				inputVec[i].second = 9;
			}
		}
		sort(inputVec.begin(),inputVec.end(),cmp);
		
		cout << "#" << tc << endl;
		for (int i = 0; i < N; i++) {
			cout << inputVec[i].first << " ";
		}
		cout << endl;
	}
	return 0;
}