package Solution;


import java.util.ArrayList;
import java.util.Scanner;

//1) ��ü����Ʈ���� ����ū�� ���� �տ� ����Ʈ������ �� ���� ��Ż�� ����
//����ū�� ���� (����ū�� ����)�ڿ��� �߶󳻼� 1)�� ���
//�������� : �����°� ����ū�� ���� �ڿ� �߶󳾰� ������ ��.
class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int N;
		int A;
		long total; //�� ������ �ٽ�;; long�� �ƴ� int�� �����ϸ� ����� test_case���� ����.
		int MAX;
		int idx_MAX;
		boolean flag = false;
		ArrayList<Integer> list;
		ArrayList<Integer> subList;
		for(int test_case = 1; test_case <= T; test_case++)
		{
			N = sc.nextInt();
			list = new ArrayList<>();
				A = 0;
				total = 0;
				MAX = 0;
				idx_MAX = -1;
				for(int i = 1; i <= N; i++) {
					A = sc.nextInt();
					list.add(A);
				}
				while(true) {
					MAX = 0;
				//list�� �ִ� ����
				for(int j = 0; j < list.size(); j++) {
					if(list.get(j)>MAX) {
						MAX = list.get(j);
						idx_MAX = j;
					}
				}
				//MAX���� ���� ����Ʈ���� �ϻ��� ��Ż�� ���ϱ�
				for(int k = idx_MAX; k >= 0; k-- ) {
					total = total + (MAX - list.get(k));
				}
				if(idx_MAX != (list.size()-1)){
					subList = new ArrayList<>(list.subList(idx_MAX+1,list.size()));
					list = new ArrayList<>(subList);
				}else {
					break;
				}
			}
			System.out.println("#" + test_case + " " + total);
		}
	}
}
