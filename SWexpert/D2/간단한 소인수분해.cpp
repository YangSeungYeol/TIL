#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	int a, b, c, d, e;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		cout << "#" << test_case << " ";
		a = 0;
		b = 0; 
		c = 0;
		d = 0;
		e = 0;
		while (N % 2 == 0) {
			a++;
			N /= 2;
		}
		while (N % 3 == 0) {
			b++;
			N /= 3;
		}
		while (N % 5 == 0) {
			c++;
			N /= 5;
		}
		while (N % 7 == 0) {
			d++;
			N /= 7;
		}
		while (N % 11 == 0) {
			e++;
			N /= 11;
		}
		cout << a << " " << b << " " << c << " " << d << " " << e << endl;
		
	}
	return 0;
}