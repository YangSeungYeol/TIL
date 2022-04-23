# 양승열
# 숫자가 낮은 바이러스 먼저 증식
# 상하좌우 따져서 비어있으면 본인숫자 채우고 차있으면 x

import sys
sys.setrecursionlimit(10 ** 6)

dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]

# 주변 4방향 공백 존재시 증식 처리
def chk_4direction(arr, x, y):
    if arr[x][y] == 0:
        return

    for d in dir:
        nx = x + d[0]
        ny = y + d[1]

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if arr[nx][ny] == 0:
            tmp_arr[nx][ny] = arr[x][y]


# 입력부
n, k = map(int, input().split())
arr_map = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())
tmp_arr = arr_map
tmp_arr1 = [[0]*n for _ in range(n)]
for sec in range(s):

    for i in range(n):
        for j in range(n):
            if arr_map[i][j] != 0:
                chk_4direction(arr_map, i, j)
                print(i, j, "000", arr_map)
                print(i, j, "000", tmp_arr)
                print(i, j, "000", tmp_arr1)
    print("11", arr_map)

# 출력부
print(arr_map[0])
print(arr_map[1])
print(arr_map[2])
print(arr_map[x-1][y-1])
