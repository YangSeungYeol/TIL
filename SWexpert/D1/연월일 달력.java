package Solution;

import java.util.Scanner;


class Solution
{
	
	
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		String S = "";
		int YYYY,MM,DD = 0;

		for(int test_case = 1; test_case <= T; test_case++)
		{
			S = sc.next();
			YYYY = Integer.valueOf(S.substring(0,4));
			MM = Integer.valueOf(S.substring(4,6));
			DD = Integer.valueOf(S.substring(6));

			if((YYYY<0)||(MM>12)||(MM<1)||(DD<1)||(DD>31)) {
				System.out.println("#"+test_case+" -1");
			}else if(((MM == 2)&&(DD>28))||((MM == 4)||(MM == 6)||(MM == 9)||(MM == 11))&&(DD>30)) {
				System.out.println("#"+test_case+" -1");
			}else {
			System.out.println("#"+test_case+" "+S.substring(0,4)+"/"+S.substring(4,6)+"/"+S.substring(6));
			}
		}
	}
}
