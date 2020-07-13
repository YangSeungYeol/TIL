package Solution;

import java.util.Arrays;
import java.util.Scanner;


class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int a[] = new int[T+1];

		for(int test_case = 1; test_case <= T; test_case++)
		{
			a[test_case] = sc.nextInt();
		}
		Arrays.sort(a);
		System.out.println(a[T/2+1]);
	}
}
