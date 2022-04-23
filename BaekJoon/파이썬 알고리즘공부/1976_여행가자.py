# 양승열
# 입력부
n = int(input())
m = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
travel_plan = list(map(int, input().split()))
is_possible = True
chk_possible = [0*(n-1)]


def dfs(start, dst, idx):
    print(start, dst, "z")
    if start == dst:
        chk_possible[idx] = 1
        return
    for i in range(n):
        if arr[start - 1][i] == 0:
            continue
        dfs(i + 1, dst, idx)


for i in range(n-1):
    dfs(travel_plan[i], travel_plan[i + 1], i)
    print("A")
print(chk_possible)
