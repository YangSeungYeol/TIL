package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		int result = 0;
		for(int i = 0; i <= A; i++) {
			result = (int)Math.pow(2, i);
			System.out.print(result+" ");
		}
		sc.close();
	}
}
