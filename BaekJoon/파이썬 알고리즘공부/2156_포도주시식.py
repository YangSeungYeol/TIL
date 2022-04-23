# 양승열
wine_list = [0]
# 입력부
n = int(input())
for _ in range(n):
    wine_list.append(int(input()))

DP = [0 for _ in range(n+1)]

# DP[0] ~ DP[2] 할당
DP[1] = wine_list[1]
DP[2] = DP[1] + wine_list[2]

# 규칙에 따른 포도주 합
for i in range(3, n+1):
    DP[i] = max(DP[i - 3] + wine_list[i - 1] + wine_list[i], DP[i - 2] + wine_list[i], DP[i - 1])

print(DP[n])
