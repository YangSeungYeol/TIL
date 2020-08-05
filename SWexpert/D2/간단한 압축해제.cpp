#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	char C[10];
	int K[10];
	int width;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> C[i] >> K[i];
		}
		cout << "#" << test_case << endl;
		width = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < K[i]; j++) {
				if (width == 10) {
					cout << endl;
					width = 0;
				}
				cout << C[i];
				width += 1;
			}
		}
		cout << endl;
	}
	return 0;
}