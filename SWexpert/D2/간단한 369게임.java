package Solution;

import java.util.Scanner;

class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		boolean flag; // 3,6,9�� �ϳ��� �ִ¼��ΰ�?
		int quo;
		int rem;

		for (int test_case = 1; test_case <= T; test_case++) {
			flag = false;
			quo = test_case;
			// 3,6,9�� ������ ���ڸ� �� 3,6,9�� ��ֳ� Ž���ϴ� ����
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

