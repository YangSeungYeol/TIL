package Solution;

import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		int N;
		int M;
		int temp;
		int result;
		T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++ ) {
			//------- ��ǲ�� �迭�� �ֱ� ����.
			N = sc.nextInt();
			M = sc.nextInt();
			int[][] NxN_Arr = new int[N][N];
			int[][] MxM_Arr = new int[M][M];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					NxN_Arr[i][j] = sc.nextInt();
				}
			}
			//------- ��ǲ�� �迭�� �ֱ� ��.
			result = 0;
			//k = �ĸ�ä ��ü �����̴� Ƚ��
			for(int l = 0; l < N-M+1; l++) {
				for(int k = 0; k < N-M+1; k++) {
					temp = 0;
					////�ĸ�ä ũ�� ���� ��ҵ� ���ϱ�
					for(int i = l; i < l+M; i++) {
						for(int j = k; j < k+M; j++) {
							temp = temp + NxN_Arr[i][j];
						}
					}
					if(temp>result) {
						result = temp;
					}
					////------------------
				}
			}
			
			
			
			System.out.println("#"+test_case+" " + result);
		}
	}
}

