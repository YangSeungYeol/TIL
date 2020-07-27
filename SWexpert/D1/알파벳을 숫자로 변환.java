package Solution;


import java.util.Scanner;
import java.io.FileInputStream;


class Solution {
	public static void main(String args[]) throws Exception {
		
		Scanner sc = new Scanner(System.in);
		String S;
		S = sc.nextLine();
		String N;
		for (int test_case = 0; test_case < S.length(); test_case++) {
			N = (S.charAt(test_case) - 'A' + 1 + " ");
			System.out.print(N);
		}
	}
}
