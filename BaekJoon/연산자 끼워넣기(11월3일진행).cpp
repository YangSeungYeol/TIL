#include<iostream>

using namespace std;

int N, A[100],oper[4],maxAns,minAns;
bool visited[100];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
}

void dfs(//�Ķ���ͻ����غ���) {


}

int main() {
	input();


	dfs();

	cout << maxAns << '\n' << minAns;
	return 0;
}

//dfs�� ������ ���� ����־ ����ū�� ���������� �̾Ƴ���. ������ ����