# 양승열

n = int(input())
weights = list(map(int, input().split())) + [0]
m = int(input())
beads = list(map(int, input().split()))

max_weight = sum(weights) + max(beads)
dp = [[False]*max_weight for _ in range(n + 1)]
# dp[x][y] : x번까지의 추를 사용했을 때 y 무게를 만들 수 있는지에 대한 여부


def chk_bead_weight(idx, wgt):
    if idx > n or dp[idx][wgt]:
        return
    dp[idx][wgt] = True
    chk_bead_weight(idx + 1, wgt + weights[idx])
    chk_bead_weight(idx + 1, abs(wgt - weights[idx]))
    chk_bead_weight(idx + 1, wgt)


chk_bead_weight(0, 0)

# for i in dp:
#     print(i)

for bead in beads:
    if bead > max_weight:
        print('N', end=' ')
    elif dp[-1][bead]:
        print('Y', end=' ')
    else:
        print('N', end=' ')
