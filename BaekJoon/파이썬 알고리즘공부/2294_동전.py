# 문제 : n가지 종류의 동전을 조합하여 k를 만들 수 있는 최소 동전 개수를 구하라. DP문제..
coin_value = []     # ex) [1, 5, 12]

n, k = map(int, input().split())
for i in range(n):
    coin_value.append(int(input()))
coin_value.sort()

DP = [10001 for _ in range(k+1)]
DP[0] = 0

for i in coin_value:
    for j in range(i, k+1):
        DP[j] = min(DP[j], DP[j - i] + 1)

if DP[k] == 10001:
    print(-1)
else:
    print(DP[k])
