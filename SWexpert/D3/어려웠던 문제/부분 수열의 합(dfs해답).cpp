#include <cstdio>

using namespace std;

int n, s, sum, T,cnt;
int arr[20];

void dfs(int i, int sum) {
    if (i == n) return;
    if (sum+arr[i] == s) cnt++;
    
    dfs(i+1, sum);
    dfs(i+1, sum + arr[i]);
}

int main(int argc, char** argv) {
    scanf_s("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf_s("%d %d", &n, &s);
        for (int i = 0; i < n; i++) { 
            scanf_s("%d", &arr[i]); 
        }
        cnt = 0;
        dfs(0, 0);
        printf("#%d %d\n", tc,cnt);
    }
    return 0;
}