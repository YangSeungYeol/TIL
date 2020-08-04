#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int arr[7][7];
	int rotate90[7][7];
	int rotate180[7][7];
	int rotate270[7][7];
	scanf_s("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf_s("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf_s("%d",&arr[i][j]);
			}
		}
		printf("#%d\n", test_case);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rotate90[i][j] = arr[N-1 -j][i];
				printf("%d",rotate90[i][j]);
			}
			printf(" ");
			for (int j = 0; j < N; j++) {
				rotate180[i][j] = arr[N - 1 - i][N - 1 - j];
				printf("%d", rotate180[i][j]);
			}
			printf(" ");
			for (int j = 0; j < N; j++) {
				rotate270[i][j] = arr[j][N-1-i];
				printf("%d", rotate270[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}