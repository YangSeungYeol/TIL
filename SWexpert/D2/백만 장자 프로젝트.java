package Solution;


import java.util.ArrayList;
import java.util.Scanner;

//1) 전체리스트에서 제일큰수 기준 앞에 리스트변수들 싹 빼서 토탈에 더해
//제일큰수 기준 (제일큰수 빼고)뒤에만 잘라내서 1)을 계속
//종료조건 : 끝나는건 제일큰수 빼고 뒤에 잘라낼게 없으면 끝.
class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int N;
		int A;
		long total; //이 문제의 핵심;; long이 아닌 int로 설정하면 헤비한 test_case에서 막힘.
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
				//list의 최댓값 추출
				for(int j = 0; j < list.size(); j++) {
					if(list.get(j)>MAX) {
						MAX = list.get(j);
						idx_MAX = j;
					}
				}
				//MAX기준 앞의 리스트변수 싹빼서 토탈에 더하기
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
