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
			//------- 인풋값 배열에 넣기 시작.
			N = sc.nextInt();
			M = sc.nextInt();
			int[][] NxN_Arr = new int[N][N];
			int[][] MxM_Arr = new int[M][M];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					NxN_Arr[i][j] = sc.nextInt();
				}
			}
			//------- 인풋값 배열에 넣기 끝.
			result = 0;
			//k = 파리채 전체 움직이는 횟수
			for(int l = 0; l < N-M+1; l++) {
				for(int k = 0; k < N-M+1; k++) {
					temp = 0;
					////파리채 크기 내부 요소들 더하기
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

