package Solution;


import java.util.ArrayList;
import java.util.Scanner;

// �ش񰪿��� ���� ������ ���� �ڵ� -> ��Ÿ�ֽĴ���...?
class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int N;
		int A;
		int total;
		int idx;
		int p_idx;
		ArrayList<Integer> list;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			list = new ArrayList<>();
			A = 0;
			total = 0;
			idx = 0;
			p_idx = -1;
			for(int i = 1; i <= N; i++) {
				A = sc.nextInt();
				list.add(A);
			}
			//list�� ���� ���� ���� ������ ū��츦 �̾Ƴ���.
			for(int j = 0; j < list.size()-2; j++) {
				if((list.get(j)<list.get(j+1))&&(list.get(j+1)>list.get(j+2))) { //�ش� ����
						idx	= j+1;
						for(int k = idx; k >= p_idx; k-- ) {
							total = total + (list.get(idx)-list.get(k));
						}
						p_idx = idx;
				}
			}
			if((list.get(N-2))<(list.get(N-1))) {
				idx = N-1;
				for(int p = idx; p >= p_idx; p--) {
					total = total + (list.get(idx)-list.get(p));
				}
			}
			System.out.println("#" + test_case + " " + total);
		}
	}
}
