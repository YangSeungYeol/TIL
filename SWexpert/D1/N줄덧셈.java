package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int T=sc.nextInt();
		int result = 0;
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			result += test_case;
		}
		System.out.println(result);
		sc.close();
	}
}
