#include<string>
#include<iostream>
#include<vector>

using namespace std;

vector<int>answer;

int convert(int N,int k);
int digitMulti(int num);

int main() {
	for (int i = 2; i < 10; i++) {
		int N = 14;
		int result = convert(N,i);
		int ans = digitMulti(result);
		cout << result << " " << ans << endl;
		if (answer.empty()) {
			answer.push_back(i);
			answer.push_back(ans);
		}
		else if (answer[1] <= ans) {
			answer[0] = i;
			answer[1] = ans;
		}
	}
	cout << answer[0] << " " << answer[1] << endl;
	return 0;
}

int convert(int N,int k) {
	int result = 0;
	for (int i = 1; N > 0; i *= 10) {
		int num = N % k;
		result += num * i;
		N /= k;
	}
	return result;
}

int digitMulti(int num) {
	int result = 1;
	while (num != 0) {
		if (num % 10 != 0)
			result *= num % 10;
		num = num / 10;
	}
	return result;
}