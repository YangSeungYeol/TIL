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

void dfs(//파라미터생각해보기) {


}

int main() {
	input();


	dfs();

	cout << maxAns << '\n' << minAns;
	return 0;
}

//dfs로 연산자 전부 집어넣어서 가장큰값 가장작은값 뽑아내기. 음수도 조심