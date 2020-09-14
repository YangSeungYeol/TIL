#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int test_case, T, ans,N;
int arr[100][100];
int row,col


int main(int argc, char** argv)
{
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {
					col++;
				}
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}