package Solution;

import java.util.Arrays;
import java.util.Scanner;
 
 
 
class Solution
{
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        int N; //NxN �ܾ� ����
        int K; //Ư���ܾ��� ���� K
        int ans;
        int num;
        T = sc.nextInt();
        for (int test_case = 1; test_case <= T; test_case++) {
        	N = sc.nextInt();
        	K = sc.nextInt();
        	int[][] binaryArr = new int[N][N];
        	ans = 0;
        	//NxN �ܾ������� �Ͼ�� 1 �������κ� 0�� �迭�� �����
        	for(int i = 0; i < N; i++) {
        		for(int j = 0; j < N; j++) {
        			binaryArr[i][j] = sc.nextInt();
        		}
        	}
        	//���ӵ� 1�� K�� ���� �����ؾ���.
        	//�迭 ���� Ž��
        	
        	for(int k = 0; k < N; k++) {
        		num = 0;
        		for(int l = 0; l < N; l++) {
        			if(binaryArr[k][l] == 1) {
        				num += 1;
        			}else {
        				num = 0;
        			}
        			if(l!=N-1&&num == K) {
        				if(binaryArr[k][l+1] == 0) {
        					ans += 1;
        				}
        			}
        			if(l == N-1&&num == K) {
        				ans += 1;
        			}
        		}
        	}
        	//�迭 ���� Ž��
        	for(int k = 0; k < N; k++) {
        		num = 0;
        		for(int l = 0; l < N; l++) {
        			if(binaryArr[l][k] == 1) {
        				num += 1;
        			}else {
        				num = 0;
        			}
        			if(l!=N-1&&num == K) {
        				if(binaryArr[l+1][k] == 0) {
        					ans += 1;
        				}
        			}
        			if(l == N-1&&num == K) {
        				ans += 1;
        			}
        		}
        	}
            System.out.println("#"+ test_case +" " + ans ); 
        }
    }
}