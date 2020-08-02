package Solution;

import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++ ) {
			int[] Arr = new int[10];
			int MAX = 0;
			int MIN = 10000;
			int sum = 0;
			int avg = 0;
			for(int i = 0; i < 10; i++) {
				Arr[i] = sc.nextInt();
			}
			for(int i = 0; i < 10; i++ ) {
				if(MAX<Arr[i]) {
					MAX = Arr[i];
				}
				if(MIN>Arr[i]) {
					MIN = Arr[i];
				}
			}
			for(int i = 0; i < 10; i++) {
				if((Arr[i] != MAX)&&(Arr[i] != MIN)) {
					sum = sum + Arr[i];
				}
			}
			avg =(int)Math.round(sum/8.0);
			System.out.println("#"+test_case+" "+avg);
		}
	}
}

