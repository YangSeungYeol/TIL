#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int m1, m2, d1, d2;
	int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int result;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = 1;
		cin >> m1 >> d1 >> m2 >> d2;
		if (m1 == m2) {
			result += abs(d2 - d1);
		}
		else {
			for (int i = m1; i < m2 - 1; i++) {
				result += arr[i];
			}
			result += arr[m1 - 1] - d1;
			result += d2;
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}