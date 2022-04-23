# 양승열
# 숫자가 낮은 바이러스 먼저 증식
# 상하좌우 따져서 비어있으면 주변탐색해서 제일작은걸로 채우고 차있으면 x
import copy

dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
vir = []


def chk_4direction(arr, x, y):  # 본인 0(공백)인 경우 주변 4방향 탐색 후 가장 작은 값으로 대체
    if arr[x][y] != 0:
        return

    vir.clear()
    for d in dir:
        nx = x + d[0]
        ny = y + d[1]

        if nx < 0 or ny < 0 or nx >= n or ny >= n:
            continue
        if arr[nx][ny] != 0:
            vir.append(arr[nx][ny])

    if len(vir) > 0:
        tmp_arr[x][y] = min(vir)


# 입력부
n, k = map(int, input().split())
arr_map = [list(map(int, input().split())) for _ in range(n)]
s, x, y = map(int, input().split())
tmp_arr = copy.deepcopy(arr_map)

for sec in range(s):
    for i in range(n):
        for j in range(n):
            if arr_map[i][j] == 0:
                chk_4direction(arr_map, i, j)

    arr_map = copy.deepcopy(tmp_arr)

# 출력부
print(arr_map[x-1][y-1])
