package Solution;

import java.util.Scanner;


class Solution
{
	
	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int sum = 0;

		while(T!=0) {
			sum = sum + T%10;
			T = T/10;
		}
		System.out.println(sum);
	}
	
	
}
