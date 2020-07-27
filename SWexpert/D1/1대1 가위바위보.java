package Solution;


import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		int B = sc.nextInt();
		// 가위 1 / 바위 2 / 보 3 
		if((A==1&&B==2)||(A==2&&B==3)||(A==3&&B==1)) {
			System.out.println("B");
		}else if((A==1&&B==3)||(A==2&&B==1)||(A==3&&B==2)){
			System.out.println("A");
		}
		sc.close();
	}
}
