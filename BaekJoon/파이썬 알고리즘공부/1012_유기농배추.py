# 양승열
import sys
sys.setrecursionlimit(10 ** 6)

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]


# 주변 4방향 배추 존재시 0처리
def chk_around(arr, x, y):
    if arr[x][y] == 0:
        return

    arr[x][y] = 0

    for d in dir:
        nx = x + d[0]
        ny = y + d[1]

        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue
        if arr[nx][ny] == 1:
            chk_around(arr, nx, ny)


# 입력부
tc = int(input())
for _ in range(tc):
    m, n, k = map(int, input().split())
    arr_map = [[0]*m for _ in range(n)]

    for _ in range(k):
        a, b = map(int, input().split())
        arr_map[b][a] = 1

    cnt = 0

    for i in range(n):
        for j in range(m):
            if arr_map[i][j] == 1:
                cnt += 1
                chk_around(arr_map, i, j)

    # 출력부
    print(cnt)
