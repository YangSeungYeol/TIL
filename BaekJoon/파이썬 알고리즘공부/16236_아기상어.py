# 양승열
from collections import deque
# 맨 처음 아기 상어 크기 2
# 1초에 한칸 움직임 (상 하 좌 우)
# 먹을 수 있는 물고기 0마리 == 엄마 상어 도움 요청 (현재 까지 시간 리턴)
# 먹을 수 있는 물고기 1마리 == 해당 물고기 먹으러 이동
# 먹을 수 있는 물고기 2마리 이상 == 가장 가까운 물고기 먹으러 이동
#  - 거리가 같을 경우 가장 <위>, 가장 <왼쪽> 물고기 먼저                   --> 이걸 어떻게 컨트롤하지..?
# 자신의 크기와 같은 수만큼 물고기 먹으면 아기 상어 크기 1증가              OK
# 아기 상어와 크기가 같은 물고기 먹지 못함, 그 위치로 이동은 가능            OK
# 아기 상어 보다 큰 물고기 먹지 못함, 그 위치로 이동도 불가능               OK
# 아기 상어 보다 작은 물고기 먹을 수 있음

# 아기 상어가 도움 요청 않고 <물고기 잡아 먹을 수 있는 시간> 출력

# map_list 값 설명
# 0 : 빈칸
# 1~6 : 칸의 물고기 크기
# 9 : 아기 상어 위치 (아기 상어 초기 크기는 2임)

dir = [(-1, 0), (0, -1), (0, 1), (1, 0)]
shark_size = 2
baby_shark = []
time = 0
eat_fish = 0
# 입력부
n = int(input())
map_list = [list(map(int, input().split())) for _ in range(n)]
print(map_list)


# BFS 수행
def bfs(x, y, size):
    visited = [[False] * n for _ in range(n)]
    distance = [[0] * n for _ in range(n)]

    q = deque()
    q.append((x, y))
    visited[x][y] = True

    while q:
        xx, yy = q.popleft()
        for d in dir:
            nx = xx + d[0]
            ny = yy + d[1]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if map_list[nx][ny] <= size:  # 비어 있거나 물고기 크기가 아기 상어 보다 작거나 같으면
                    q.append((nx, ny))
                    visited[nx][ny] = True
                    distance[nx][ny] = distance[xx][yy] + 1
                    if map_list[nx][ny] < size and map_list[nx][ny]:  # 아기 상어 보다 작은 고기가 존재 하는 칸
                        map_list[nx][ny] = 0
                        return nx, ny, distance[nx][ny]
    return -1, -1, 0


for i in range(n):
    for j in range(n):
        if map_list[i][j] == 9:
            map_list[i][j] = 0
            baby_shark = [2, (i, j)]
print(baby_shark[1][0], baby_shark[1][1], baby_shark[0])
while True:
    r, c, dist = bfs(baby_shark[1][0], baby_shark[1][1], baby_shark[0])
    if r == -1:
        break
    time += dist
    eat_fish += 1
    if shark_size == eat_fish:
        shark_size += 1
        eat_fish = 0
    baby_shark = [shark_size, (r, c)]

print(time)

