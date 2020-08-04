#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int hour1;
	int minute1;
	int hour2;
	int minute2;
	int sumHour;
	int sumMinute;
	scanf_s("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf_s("%d %d %d %d", &hour1, &minute1, &hour2, &minute2);
		sumHour = hour1 + hour2;
		sumMinute = minute1 + minute2;
		if (sumMinute > 59) {
			sumMinute -= 60;
			sumHour += 1;
		}
		if (sumHour > 12) {
			sumHour -= 12;
		}
		printf_s("#%d %d %d\n", test_case, sumHour, sumMinute);
	}
	return 0;
}