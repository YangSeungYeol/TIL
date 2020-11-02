#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> score = { 1300000000,700000000,668239490,618239490,568239490,568239486,518239486,157658638,157658634,100000000,100 };
int k = 2;
vector<int> diff;

int main() {
	int answer = -1;
	for (int i = 1; i < score.size(); i++) {
		int scoreDiff = score[i - 1] - score[i];
		diff.push_back(scoreDiff);
	}
	for (int i = 0; i < diff.size(); i++) {
		int cnt = 0;
		cnt = count(diff.begin(), diff.end(), diff[i]);
		if (cnt >= k) {
			int num = diff[i];
			diff.erase(remove(diff.begin(), diff.end(), num), diff.end());
		}
	}
	answer += diff.size();
	return 0;
}