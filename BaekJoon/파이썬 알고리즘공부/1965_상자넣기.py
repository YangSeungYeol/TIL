# 양승열
# 입력부
n = int(input())
box_list = list(map(int, input().split()))
dp = [1]*n  # 넣을 수 있는 최소 상자 개수는 1개 -> 1로 dp[] 초기화

for i in range(1, n):
    for j in range(i):
        if box_list[i] > box_list[j]:
            dp[i] = max(dp[i], dp[j] + 1)
        print(dp)
# 출력부
print(max(dp))
