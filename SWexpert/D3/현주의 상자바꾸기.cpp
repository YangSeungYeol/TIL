#include<iostream>
#include<vector>
using namespace std;

vector <int>nBox;

int main(int argc, char** argv)
{
	int test_case;
	int T, N,Q,L,R;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N>>Q;

		//N개박스 값들 0으로초기화
		nBox.clear();
		for (int i = 0; i < N; i++) {
			nBox.push_back(0);
		}

		
		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;
			for (int j = L; j <= R; j++) {
				nBox[j-1] = i;
			}
		}
		cout << "#" << test_case;
		for (int i = 0; i < N; i++) {
			cout <<  " "<< nBox[i];
		}
		cout << '\n';
	}
	return 0;
}