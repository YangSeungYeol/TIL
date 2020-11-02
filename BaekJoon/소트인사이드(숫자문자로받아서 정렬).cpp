#include<iostream>
#include<algorithm>
using namespace std;

char ch_num[10];

int main() {
	cin >> ch_num;
	sort(ch_num, ch_num+strlen(ch_num),greater<int>());
	for (int i = 0; i < strlen(ch_num); i++) {
		printf("%c", ch_num[i]);
	}

	return 0;
}