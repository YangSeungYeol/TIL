#include<iostream>
#include<vector>
using namespace std;

int T, N, M,X,Y,stoneColor,startP,endP;
int arr[8][8];
vector <vector<int>> Vec;
vector<int> subVec;


int main(int argc, char** argv)
{
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> X >> Y >> stoneColor;
			subVec.push_back(X);
			subVec.push_back(Y);
			subVec.push_back(stoneColor);
			Vec.push_back(subVec);
			subVec.clear();
		}

		//오셀로판 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i == (N / 2 - 1)&&j ==(N/2-1))||(i == (N/2) && j == (N/2))) {
					arr[i][j] = 2;
				}
				else if ((i == (N / 2) && j == (N / 2 - 1))||(i == N/2-1&&j ==N/2)) {
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = 0;
				}
			}
		}

		for (int k = 0; k < M; k++) {
			arr[Vec[k][1] - 1][Vec[k][0] - 1] = Vec[k][2];
			//가로세로대각선판단 아직못짬..
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}



	}
	return 0;
}