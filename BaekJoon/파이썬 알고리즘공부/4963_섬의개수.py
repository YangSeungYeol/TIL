# 양승열
import sys
sys.setrecursionlimit(10 ** 6)

d = [[1, 0], [1, 1], [0, 1], [-1, 1], [-1, 0], [-1, -1], [0, -1], [1, -1]]


# 주변 8방향 섬 존재시 0처리
def chk_around(arr, x, y):
    if arr[x][y] == 0:
        return

    arr[x][y] = 0

    for k in d:
        nx = x + k[0]
        ny = y + k[1]

        if nx < 0 or ny < 0 or nx >= h or ny >= w:
            continue
        if arr[nx][ny] == 1:
            chk_around(arr, nx, ny)


# 입력부
while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    arr_map = [list(map(int, input().split())) for _ in range(h)]

    island_cnt = 0

    for i in range(h):
        for j in range(w):
            if arr_map[i][j] == 1:
                island_cnt += 1
                chk_around(arr_map, i, j)

    # 출력부
    print(island_cnt)

