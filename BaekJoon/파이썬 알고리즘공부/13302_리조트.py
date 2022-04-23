# 양승열
# 조건 : 1일권 - 15000원 / 3일권(쿠폰1장) - 27000원 / 5일권(쿠폰2장) - 37000원
# 최소 비용 리조트 이용
import sys
inf = sys.maxsize

# 입력부 n : 방학일 수 / m : 리조트 갈수 없는 날의 수
n, m = map(int, input().split())
no_resort = list(map(int, input().split()))

dp = [[inf]*(n+1) for _ in range(n+1)]
dp[0][0] = 0
for i in range(n+1):
    for j in range(n//3):
        if dp[i][j] == inf:
            continue
        result = dp[i][j]
        if i + 1 in no_resort:
            dp[i + 1][j] = min(result, dp[i + 1][j])
        if j >= 3:
            dp[i + 1][j - 3] = min(result, dp[i + 1][j - 3])

        # 1일권
        dp[i + 1][j] = min(dp[i + 1][j], result + 10000)
        # 3일권
        for k in range(1, 4):
            dp[i + k][j + 1] = min(dp[i + k][j + 1], result + 25000)
        # 5일권
        k = 0
        for k in range(1, 6):
            dp[i + k][j + 2] = min(dp[i + k][j + 2], result + 37000)
    print(min(dp[n]))
