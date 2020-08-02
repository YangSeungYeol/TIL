package Solution;

import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		int N;
		int[][] Arr = new int[10][];
		for(int a = 0; a < Arr.length; a++){
			Arr[a] = new int[a+1];
		}
		T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++) {
			N = sc.nextInt();
			System.out.println("#"+test_case);
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < i+1; j++) {
					Arr[i][j] = 1;
					if(i>1&&j>0&&j<i) {
						Arr[i][j]= Arr[i-1][j-1]+Arr[i-1][j];
					}
					System.out.print(Arr[i][j]);
					if(j!=i) {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}
	}
}

