#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int cnt[500000];

int main() {
	int N,avg,med,ans_mod,ans_range;
	int sum = 0;
	vector <int> num;
	vector <int> temp_mod;
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		cnt[num[i] + 4000]++;
	}
	int index = *max_element(cnt, cnt + 500000);
	for (int i = 0; i < 8001; i++) {
		if (cnt[i] == 0)continue;
		if (cnt[i] == index) {
			temp_mod.push_back(i - 4000);
		}
	}
	if (temp_mod.size() > 1) {
		sort(temp_mod.begin(), temp_mod.end());
		ans_mod = temp_mod[1];
	}
	else {
		ans_mod = temp_mod[0];
	}
	for (int i = 0; i < N; i++) {
		sum += num[i];
	}
	avg = round((double)sum / (double)N);
	sort(num.begin(), num.end());
	med = num[N / 2];
	ans_range = num.back() - num.front();
	printf("%d\n%d\n%d\n%d", avg, med, ans_mod, ans_range);
	return 0;
}