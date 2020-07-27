package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		sc.close();
		if(T<=100000) {
			for(int test_case = 1; test_case <= T; test_case++)
			{
				System.out.print("#");
			}
		}
	}
}
