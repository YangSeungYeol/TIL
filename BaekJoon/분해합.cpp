#include<iostream>

using namespace std;

int input,dSum,answer;

int decomposition(int num) {
	int temp;
	int ans = num;
	dSum = 0;
	dSum += num;
	for (int i = 1000000; i > 0; i /= 10) {
		temp = num / i;
		num = num % i;
		dSum += temp;
	}
	return ans;
}

int main() {
	cin >> input;
	int n = 1;
	while (dSum != input) {
		if (n > input) {
			answer = 0;
			break;
		}
		answer = decomposition(n);
		n++;
	}
	cout << answer << endl;
	return 0;
}