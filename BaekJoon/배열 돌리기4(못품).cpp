#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

int N, M, K;
int A[50][50];
int rcs[6][3];
vector <int> order;
int allCases[][3];
void rotate() {


}

void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		for (int i = 0; i < order.size(); i++) {
			cin >> allCases[0][i];
		}
		cout << endl;
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(order[i], order[depth]);
		makePermutation(n, r, depth + 1);
		swap(order[i], order[depth]);
	}
	return;
}




int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> rcs[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
			order.push_back(i);
		
	}
	makePermutation(K, K, 0);

	
	for (int i = 0; i < K; i++) {
		

	}



	//행의 합 중 가장 작은값 도출



	return 0;
}