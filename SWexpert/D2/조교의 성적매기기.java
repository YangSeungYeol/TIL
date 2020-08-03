package Solution;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Solution {
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;// �׽�Ʈ���̽� ��
		int N;// �л� ��
		int K;// ������ �˰���� �л� ��ȣ
		int totalScore = 0;
		T = sc.nextInt();
		for (int test_case = 1; test_case <= T; test_case++) {
			N = sc.nextInt();
			K = sc.nextInt();
			int[][] scoreArr = new int[N][3]; // �л����� ���� 1��:�߰���� 2��:�⸻��� 3��:����
			int[][] totalScoreArr = new int[N][3];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 3; j++) {
					scoreArr[i][j] = sc.nextInt();
				}
			}
			for (int k = 0; k < N; k++) {
				totalScoreArr[k][0] = (scoreArr[k][0] * 35) + (scoreArr[k][1] * 45) + (scoreArr[k][2] * 20);
				totalScoreArr[k][1] = k + 1; // totalScoreArr�� �ι�° ���� �л� ��ȣ �Űܵα�
				totalScoreArr[k][2] = 0;
			}

			Arrays.sort(totalScoreArr, new Comparator<int[]>() {

				@Override
				public int compare(int[] o1, int[] o2) {
					return o2[0] - o1[0];
				}
			});
			
			for(int l = 0; l < N; l++) {
				totalScoreArr[l][2] = l+1;
			}
			for(int m = 0; m < N; m++) {
				if(totalScoreArr[m][1] == K) {
					totalScore = totalScoreArr[m][2]; 
				}
			}
			if(totalScore == 0) {
				System.out.println("K���� �߸� �ԷµǾ����ϴ�.");
			}else if((totalScore/(double)N*100)<=10){
				System.out.println("#"+ test_case + " A+");
			}else if((totalScore/(double)N*100)<=20) {
				System.out.println("#"+ test_case + " A0");
			}else if((totalScore/(double)N*100)<=30) {
				System.out.println("#"+ test_case + " A-");
			}else if((totalScore/(double)N*100)<=40) {
				System.out.println("#"+ test_case + " B+");
			}else if((totalScore/(double)N*100)<=50) {
				System.out.println("#"+ test_case + " B0");
			}else if((totalScore/(double)N*100)<=60) {
				System.out.println("#"+ test_case + " B-");
			}else if((totalScore/(double)N*100)<=70) {
				System.out.println("#"+ test_case + " C+");
			}else if((totalScore/(double)N*100)<=80) {
				System.out.println("#"+ test_case + " C0");
			}else if((totalScore/(double)N*100)<=90) {
				System.out.println("#"+ test_case + " C-");
			}else{
				System.out.println("#"+ test_case + " D0");
			}
			
		}
	}
}
