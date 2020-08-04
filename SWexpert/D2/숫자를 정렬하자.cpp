#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int num;
	vector<int> vec;
	scanf_s("%d",&T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf_s("%d", &num);
			vec.push_back(num);
		}
		sort(vec.begin(), vec.end());
		printf("#%d ", test_case);
		for (int j = 0; j < vec.size(); j++) {
			if (j == vec.size() - 1) {
				printf("%d\n", vec.at(j));
				break;
			}
			printf("%d ", vec.at(j));
		}
	}
	return 0;
}