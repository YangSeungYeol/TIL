package Solution;

import java.util.Arrays;
import java.util.Scanner;
 
 
 
class Solution
{
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        int N; //NxN 단어 퍼즐
        int K; //특정단어의 길이 K
        int ans;
        int num;
        T = sc.nextInt();
        for (int test_case = 1; test_case <= T; test_case++) {
        	N = sc.nextInt();
        	K = sc.nextInt();
        	int[][] binaryArr = new int[N][N];
        	ans = 0;
        	//NxN 단어퍼즐을 하얀색 1 검은색부분 0인 배열로 만들기
        	for(int i = 0; i < N; i++) {
        		for(int j = 0; j < N; j++) {
        			binaryArr[i][j] = sc.nextInt();
        		}
        	}
        	//연속된 1이 K의 수와 동일해야함.
        	//배열 가로 탐색
        	
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
        	//배열 세로 탐색
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