#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arrVC[100][2];
vector <pair<int,int>> vec;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, N, K, V, C,cnt;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		cin >> N >> K; //K�� ������ ����
		for (int i = 0; i < N; i++) {
			cin >> V; //V�� ������ ����
			cin >> C; //C�� ������ ��ġ
			vec.push_back({ V,C });
		}
		//��ġ�� ū������ ����
		sort(vec.begin(), vec.end(),cmp);
		reverse(vec.begin(), vec.end());

		for (int i = 0; i < N; i++) {
			cout << vec[i].first<<" "<<vec[i].second << endl;
		}
		//K���ǿ� ���� �� �ִ� �ִ� ��ġ
		//��ġ������ ����. arrVC�� 1���� ���� ���ؼ� 5���Ϸ� ���� �� �ִ� ��� ��츦 ���Ͽ� ���Ϳ� �����ϰ� ����ū������
		int currentV = 0;
		int currentC = 0;
		for (int i = 0; i < N; i++) {
			if (currentV < K){
				currentV += vec[i].first;
				currentC += vec[i].second;
			}

		}

		
	}
	return 0;
}