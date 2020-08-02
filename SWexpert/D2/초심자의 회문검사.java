package Solution;

import java.util.Scanner;


class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++ ) {
			String str = sc.next();
			String subStr1 = "";
			String subStr2 = "";
			StringBuffer tempStr = new StringBuffer();
			int str_length = str.length();
			if(str_length%2==0) {
				subStr1 = str.substring(0,str_length/2);
				subStr2 = str.substring(str_length/2);
			}else {
				subStr1 = str.substring(0,str_length/2);
				subStr2 = str.substring(str_length/2+1);
			}
			tempStr.append(subStr2);
			tempStr.reverse();
			subStr2 = String.valueOf(tempStr);
			if(subStr1.equals(subStr2)) {
				System.out.println("#"+test_case+" " + 1);
			}else {
				System.out.println("#"+test_case+" " + 0);
			}
		}
	}
}

