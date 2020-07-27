package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		for(int i = A; i >= 0; i--) {
			System.out.print(i+" ");
		}
		sc.close();
	}
}
