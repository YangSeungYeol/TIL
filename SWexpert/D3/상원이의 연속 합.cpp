#include<iostream>
#include<vector>
using namespace std;

int tc,T, N,sum,cnt;
vector <int> num;
int main(int argc, char** argv)
{
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		num.clear();
		cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			num.push_back(i+1);
		}
		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				sum += num[j];
				if (sum > N) {
					break;
				}
				else if (sum == N) {
					cnt++;
				}
			}
			sum = 0;
		}
		cout << "#" << tc << " " << cnt << endl;
	}
	return 0;
}