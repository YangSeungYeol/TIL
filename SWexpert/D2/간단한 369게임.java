package Solution;

import java.util.Scanner;

class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		boolean flag; // 3,6,9가 하나라도 있는수인가?
		int quo;
		int rem;

		for (int test_case = 1; test_case <= T; test_case++) {
			flag = false;
			quo = test_case;
			// 3,6,9가 있으면 각자리 에 3,6,9가 몇개있나 탐색하는 루프
			while (true) {
				rem = quo % 10;
				quo = quo / 10;
				if (rem == 3 || rem == 6 || rem == 9) {
					System.out.print("-");
					flag = true;
				} 
				if(quo == 0) {
					break;
				}
			}
			if (flag == false) {
				System.out.print(test_case);
			}
			if (test_case != T) {
				System.out.print(" ");
			}
		}
	}
}

