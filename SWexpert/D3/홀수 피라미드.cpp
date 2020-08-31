#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	long long int N,X,Y;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		long long leftV;
		long long rightV;
		cin >> N;
		leftV = (N-1) * (N-1) * 2 + 1;
		rightV = N * N * 2 - 1;
		cout << "#" << test_case << " " << leftV << " " << rightV << endl;;
	}
	return 0;
}