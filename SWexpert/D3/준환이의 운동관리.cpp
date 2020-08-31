#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, E, L,U,X,ans;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> L >> U >> X;
		if (X > U) {
			ans = -1;
		}
		else if (X < L) {
			ans = L - X;
		}
		else {
			ans = 0;
		}



		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}