#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int m1, m2, d1, d2;
	int arr[12][2] = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
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
				result += arr[i][1];
			}
			result += arr[m1 - 1][1] - d1;
			result += d2;	
		}
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}