#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int a;
	int b;
	int result;
	int speed;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf_s("%d", &N);
		result = 0;
		speed = 0;
		for (int i = 0; i < N; i++) {
			cin >> a;
			if(a!=0){
				cin >> b;
			}
			if (a == 0) {//유지
				result += speed;
			}
			if (a == 1) {//가속
				speed += b;
				result += speed;
			}
			if (a == 2 && speed >= b) {//감속
				speed -= b;
				result += speed;
			}
		}
		printf("#%d %d\n", test_case, result);
	}
	return 0;
}