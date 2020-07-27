package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		for(int i = 1; i <= a; i++) {
			if(a%i == 0) {
				System.out.print(i+ " ");
			}
		}
		sc.close();
	}
}
