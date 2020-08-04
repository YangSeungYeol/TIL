#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int M;
	int num;
	vector<int> Ai;
	vector<int> Bj;
	int diffVecSize;
	int smallVectorSize;
	int result;
	int temp;
	scanf_s("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		Ai.clear();
		Bj.clear();
		scanf_s("%d", &N);
		scanf_s("%d", &M);
		for (int i = 0; i < N; i++) {
			scanf_s("%d",&num);
			Ai.push_back(num);
		}
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &num);
			Bj.push_back(num);
		}
		diffVecSize = Ai.size() - Bj.size();
		result = 0;
		if (diffVecSize > 0) {
			smallVectorSize = Bj.size();
			for (int k = 0; k < abs(diffVecSize)+1; k++) {
				temp = 0;
				for (int l = 0; l < smallVectorSize; l++) {
					temp = temp + (Bj[l] * Ai[k+l]);
				}
				if (temp > result) {
					result = temp;
				}
			}
		}else {
			smallVectorSize = Ai.size();
			for (int k = 0; k < abs(diffVecSize)+1; k++) {
				temp = 0;
				for (int l = 0; l < smallVectorSize; l++) {
					temp = temp + (Bj[k+l] * Ai[l]);
				}
				if (temp > result) {
					result = temp;
				}
			}
		}
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}