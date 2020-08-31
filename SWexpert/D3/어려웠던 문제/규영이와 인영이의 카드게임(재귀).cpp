#include<iostream>
#include<vector>
using namespace std;

int win;
int lose;
bool checkArr[9];
int gyuYoung[9];
int inYoung[9];
void func(int gyuScore,int inScore,int round) {
	if (round > 9) {
		if (gyuScore > inScore) { win++; return; }
		else { lose++; return; }
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (checkArr[i] == false) {
			checkArr[i] = true;
			if (gyuYoung[round - 1] > inYoung[i]) {
				func(gyuScore+(gyuYoung[round-1]+inYoung[i]), inScore, round + 1);
			}
			else if (gyuYoung[round - 1] < inYoung[i]) {
				func(gyuScore, inScore+(gyuYoung[round - 1] + inYoung[i]), round + 1);	
			}
			checkArr[i] = false;
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T,E;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		win = 0;
		lose = 0;
		int card[18] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
		for (int i = 0; i < 9; i++) {
			cin >> gyuYoung[i];
			card[gyuYoung[i]-1] = 0;
		}
		for (int i = 0; i < 18; i++) {
			cout << card[i] << " ";
		}
		
		for (int i=0 , j = 0; i < 18; i++) {
			if (card[i] != 0) {
				inYoung[j] = card[i];
				j++;
			}
		}
		func(0, 0, 1);
		cout << "규영이기는경우수: " << win << endl;
		cout << "인영이기는경우수: " << lose << endl;
	}
	return 0;
}