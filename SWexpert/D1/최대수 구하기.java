package Solution;

import java.util.Arrays;
import java.util.Scanner;


class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int a[] = new int[10];

		for(int test_case = 1; test_case <= T; test_case++)
		{
			for(int i = 0; i < 10; i++) {
				a[i] = sc.nextInt();
			}
			Arrays.sort(a);
			System.out.println("#"+test_case+" " +a[9]);

		}
	}
}
