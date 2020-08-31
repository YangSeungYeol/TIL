#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, E,line1,line2,line3,line4;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		line4 = 0;
		cin >> line1 >> line2 >> line3;
		if (line1 == line2 && line2== line3) {
			line4 = line1;
			cout << "#" << test_case << " " << line4 << endl;
			continue;
		}
		if (line1 == line2) {
			line4 = line3;
		}
		else if (line1 == line3) {
			line4 = line2;
		}
		else {
			line4 = line1;
		}
		cout << "#" << test_case << " " << line4 << endl;
	}
	return 0;
}