#include<iostream>
using namespace std;
int tc, T, x, y, ladder[102][102];
int main(int argc, char** argv)
{
	for (tc = 1; tc <= 10; ++tc)
	{
		cin >> T;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				cin >> ladder[i][j];
				if (ladder[i][j] == 2) {
					x = i;
					y = j;
				}
			}
		}
		for (int n = 99; n >= 0; n--) {
			if (ladder[n][y + 1] == 1) {
				while (true) {
					y++;
					if (ladder[n][y + 1] != 1) break;
				}
			}
			else if (ladder[n][y - 1] == 1) {
				while (true) {
					y--;
					if (ladder[n][y - 1] != 1) break;
				}
			}
		}
		cout << "#" << T << " " << y-1 << endl;
	}
	return 0;
}