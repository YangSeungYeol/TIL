# 양승열
# import sys
# sys.setrecursionlimit(10 ** 6)
# 입력부
row, col = map(int, input().split())
cheese_map = [list(map(int, input().split())) for _ in range(row)]
print(cheese_map)

d = [[1, 0], [0, 1], [-1, 0], [0, -1]]
tmp_location = []
melt_time = 0
cheese_cnt = 0


# 치즈는 1시간에 테두리 1칸씩 녹음
# (0,0)에서 시작, 4방향 탐색, 같은 0인부분 일때 계속 진행 닿은 1들의 위치 tmp_location 저장
def chk_cheese(arr, x, y):
    if arr[x][y] == 1:
        tmp_location.append([x, y])
        return
    for k in d:
        nx = x + k[0]
        ny = y + k[1]

        if nx < 0 or ny < 0 or nx >= row or ny >= col:
            continue
        if arr[nx][ny] == 0:
            chk_cheese(arr, nx, ny)


chk_cheese(cheese_map, 0, 0)

for i in tmp_location:
    cheese_map[i[0]][i[1]] = 0
print(cheese_map)
cheese_cnt += 1

print()

# 출력부 - 치즈가 모두 녹아서 없어 지는데 걸리는 시간 / 모두 녹기 한시간 전에 남은 치즈 조각 수
print(melt_time)
print(cheese_cnt)
