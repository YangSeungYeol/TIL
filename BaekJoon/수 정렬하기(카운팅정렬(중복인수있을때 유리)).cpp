#include <iostream>

using namespace std;

int cnt[10001];

int main(){ 
	int N,num;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d" ,&num);
		cnt[num]++;
	}
	for (int i = 0; i < 10001; i++) {
		if (cnt[i] == 0)continue;

		for (int j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}
