//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int N;
//vector <int> num;
//
//int comp(const void* a, const void* b) {
//	int num1 = *(int*)a;    
//	int num2 = *(int*)b;    
//
//	if (num1 > num2)    
//		return 1;      
//
//	if (num1 < num2) 
//		return -1;
//
//	return 0;
//}
//
//int main() {
//	cin >> N;
//	num.resize(N);
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//	qsort(&num[0], num.size(), sizeof(num[0]), comp);
//	for (int i = 0; i < N; i++) {
//		printf_s("%d\n", num[i]);
//	}
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int N,num[1000];
//
//int main() {
//	int temp;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> num[i];
//	}
//	for (int i = 0; i < N-1; i++) {
//		for (int j = i + 1; j < N; j++) {
//			if (num[i] > num[j]) {
//				temp = num[j];
//				num[j] = num[i];
//				num[i] = temp;
//			}
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		cout << num[i] << endl;
//	}
//	return 0;
//}

#include <stdio.h>
#define MAX 1000000

int d[MAX];
int temp[MAX];

void MergeSort(int L, int R) {
    if (L >= R) return;
    int M = (L + R) / 2;
    // Divide
    MergeSort(L, M);
    MergeSort(M + 1, R);
    // Conquer
    for (int i = L, l = L, r = M + 1;
        l != M + 1 || r != R + 1;
        i++) {

        if ((r != R + 1 && l <= M && d[l] < d[r]) || r == R + 1) {
            temp[i] = d[l++];
        }
        else {
            temp[i] = d[r++];
        }
    }

    for (int i = L; i <= R; i++) {
        d[i] = temp[i];
    }
}

int main() {
    int n;

    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
        scanf_s("%d", &d[i]);

    MergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", d[i]);
}
