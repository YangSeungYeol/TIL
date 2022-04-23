# 양승열
# 문제 유형 : 동적 계획법(DP)

# 계단 값 저장 배열
stair_value = [0]    # ex) [0, 10, 20, 15, 25, 10, 20]

# 입력부
n = int(input())
for i in range(n):
    stair_value.append(int(input()))

# 계단 합 배열 선언 및 초기화
DP = [0 for _ in range(n+1)]

# DP[0] ~ DP[2] 할당
DP[1] = stair_value[1]
DP[2] = DP[1] + stair_value[2]

# 규칙에 따른 계단 합
for i in range(3, n+1):
    DP[i] = max(DP[i - 3] + stair_value[i - 1] + stair_value[i], DP[i - 2] + stair_value[i])

print(DP[n])
