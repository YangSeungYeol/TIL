# 양승열
import copy, sys
sys.setrecursionlimit(10 ** 4)
dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
iceberg_cnt = 0
time = 0
# 입력부
n, m = map(int, input().split())
iceberg = [list(map(int, input().split())) for _ in range(n)]


# 빙산 덩어리 개수 체크
# 주변 4방향 빙산 존재시 0처리 방식
def chk_iceberg_cnt(lst, x, y):  # arr 넘길 때 deepcopy 사용 必
    if lst[x][y] == 0:
        return

    lst[x][y] = 0

    for k in dir:
        nx = x + k[0]
        ny = y + k[1]

        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue
        if lst[nx][ny]:
            chk_iceberg_cnt(lst, nx, ny)


first_iceberg = copy.deepcopy(iceberg)
iceberg_cnt = 0
for i in range(n):
    for j in range(m):
        if first_iceberg[i][j]:
            iceberg_cnt += 1
            chk_iceberg_cnt(first_iceberg, i, j)
if iceberg_cnt >= 2:
    print(time)
    exit()

while iceberg_cnt < 2:
    time += 1
    # 빙산 녹이기
    tmp_iceberg = copy.deepcopy(iceberg)
    for i in range(n):
        for j in range(m):
            if tmp_iceberg[i][j]:
                for k in dir:
                    ni = i + k[0]
                    nj = j + k[1]

                    if ni < 0 or nj < 0 or ni >= n or nj >= m:
                        continue
                    if not tmp_iceberg[ni][nj] and iceberg[i][j] > 0:  # 음수 방지
                        iceberg[i][j] -= 1

    iceberg_chk = copy.deepcopy(iceberg)
    iceberg_cnt = 0
    for i in range(n):
        for j in range(m):
            if iceberg_chk[i][j]:
                iceberg_cnt += 1
                chk_iceberg_cnt(iceberg_chk, i, j)

    if sum(map(sum, iceberg[1:-1])) == 0:  # 다 녹을 때 까지 덩어리 1개 인 경우
        print(0)
        exit()

print(time)
