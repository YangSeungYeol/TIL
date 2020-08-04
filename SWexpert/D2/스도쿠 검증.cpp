#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	vector<int> temp;
	bool is_same;
	scanf_s("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		is_same = false;
		int sudokuArr[9][9];
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf_s("%d", &sudokuArr[i][j]);
			}
		}
		//가로 같은값 체크
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = j + 1; k < 9; k++) {
					if (sudokuArr[i][j] == sudokuArr[i][k]) {
						is_same = true;
						break;
					}
				}
				if (is_same == true) {
					break;
				}
			}
			if (is_same == true) {
				break;
			}
		}
		//세로 같은값체크
		if (is_same == false) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 8; j++) {
					for (int k = j + 1; k < 9; k++) {
						if (sudokuArr[j][i] == sudokuArr[k][i]) {
							is_same = true;
							break;
						}
					}
					if (is_same == true) {
						break;
					}
				}
				if (is_same == true) {
					break;
				}
			}
		}
		//3x3 temp배열에 9개 집어넣고 같은값 체크
		if (is_same == false) {
			for (int i = 0; i < 9; i += 3) {
				for (int j = 0; j < 9; j += 3) {
					temp.clear();
					for (int p = i; p < i + 3; p++) {
						for (int q = j; q < j + 3; q++) {
							temp.push_back(sudokuArr[p][q]);
						}
					}
					for (int r = 0; r < 8; r++) {
						for (int s = r + 1; s < 9; s++) {
							if (temp[r] == temp[s]) {
								is_same = true;
								break;
							}
						}
						if (is_same == true) {
							break;
						}
					}
					if (is_same == true) {
						break;
					}
				}
				if (is_same == true) {
					break;
				}
			}

		}
		//결과출력
		if (is_same == false) {
			printf("#%d %d\n", test_case, 1);
		}
		else {
			printf("#%d %d\n", test_case, 0);
		}
	}
	return 0;
}