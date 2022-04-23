# 양승열
# DP 문제
# 입력부 -> n = 물건의 수 / k = 최대 가능 무게 / w = 물건의 무게 / v = 물건의 가치
n, k = map(int, input().split())
objects = [list(map(int, input().split())) for _ in range(n)]
objects.insert(0, [0, 0])

dp = [[0]*(k+1) for _ in range(n+1)]

# 무게를 넘지 않고 가치 합이 최대가 되는 경우 구하기
# 이전 까지 물건 넣은 경우 들 중 [i-1]
# 현재 가방의 무게[j]에서 현재 물건의 무게를 뺀[j-w]
# 최대 가치 dp[i-1][j-w]와 현재 물건의 가치를 더한 값과 +v
# 이전 까지 물건 넣은 경우 들 중 [i-1] 현재 가방의 무게[j]에서의 최대 가치 dp[i-1][j]
# 중에서 가치 합이 더 큰값 채택
for i in range(1, n+1):
    for j in range(1, k+1):
        w = objects[i][0]
        v = objects[i][1]

        if j < w:  # 최대 무게 보다 물건의 무게가 크면 윗행 값으로 저장
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)

# 출력부
print(dp[n][k])
