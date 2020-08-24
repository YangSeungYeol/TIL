#include <cstdio>
#include <iostream>
#include<vector>
using namespace std;

int T, N, M,P,Q,tmpRouteLength,maxRouteLength;
int arr[][2];
int visited[21];
vector<int> vec[10];

void dfs(int x) {
    if (visited[x]>=1) {
        return;
    }
    if (visited[x] <= 1) { tmpRouteLength++; }
    visited[x]++;
    
    cout << "tmpRL" << tmpRouteLength << endl;
    cout << x << ' ';
    for (int i = 0; i < vec[x].size(); i++) {
        int y = vec[x][i];
        dfs(y);
    }
}

int main(int argc, char** argv) {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> P;
            cin >> Q;
            vec[P].push_back(Q);
            vec[Q].push_back(P);
        }
        maxRouteLength = 0;

        for (int i = 1; i < N+1; i++) {
            tmpRouteLength = 0;
            for (int j = 0; j < 21; j++) {
                visited[j] = 0;
            }
            dfs(i);
            if (tmpRouteLength > maxRouteLength) {
                maxRouteLength = tmpRouteLength;
            }
        }
        printf("#%d %d\n", tc, maxRouteLength);
    }
    return 0;
}