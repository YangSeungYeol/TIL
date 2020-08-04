#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int money;
	int numOf50000;
	int numOf10000;
	int numOf5000;
	int numOf1000;
	int numOf500;
	int numOf100;
	int numOf50;
	int numOf10;
	scanf_s("%d",&T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf_s("%d", &money);
		numOf50000 = money / 50000;
		numOf10000 = (money % 50000) / 10000;
		numOf5000 = ((money % 50000) % 10000) / 5000;
		numOf1000 = (((money % 50000) % 10000) % 5000) / 1000;
		numOf500 = ((((money % 50000) % 10000) % 5000) % 1000) / 500;
		numOf100 = (((((money % 50000) % 10000) % 5000) % 1000) % 500) / 100;
		numOf50 = ((((((money % 50000) % 10000) % 5000) % 1000) % 500) % 100) / 50;
		numOf10 = (((((((money % 50000) % 10000) % 5000) % 1000) % 500) % 100) % 50) / 10;
		printf_s("#%d\n%d %d %d %d %d %d %d %d\n", test_case,numOf50000, numOf10000, numOf5000, numOf1000, numOf500, numOf100, numOf50, numOf10);
	}
	return 0;
}