package Solution;

import java.util.Scanner;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int sum;
		int temp = 0;

		for(int test_case = 1; test_case <= T; test_case++)
		{
			sum = 0;
			for(int i = 0; i <10; i++) {
				temp = sc.nextInt();
				sum += temp;
			}
			System.out.println("#"+test_case+" "+Math.round(sum/10.0));
		}
	}
}
