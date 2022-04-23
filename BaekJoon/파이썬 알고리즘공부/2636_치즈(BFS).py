# 양승열 -- 방문 배열 펑션안에 넣어줘야함. 한시간 돌때마다 false로 초기화해야하기때문에..
from collections import deque

# 입력부
row, col = map(int, input().split())
cheese_map = [list(map(int, input().split())) for _ in range(row)]

d = [[1, 0], [0, 1], [-1, 0], [0, -1]]
tmp_location = []
melt_time = 0
cheese_cnt = 0
cheese_arr = []


# 치즈는 1시간에 테두리 1칸씩 녹음
# (0,0)에서 시작, 4방향 탐색, 같은 0인부분 일때 계속 진행 닿은 1들의 위치 tmp_location 저장
def cheese_bfs(x, y):
    visited = [[False]*col for _ in range(row)]
    q = deque()
    q.append([x, y])
    visited[x][y] = True
    cnt = 0
    while q:
        x, y = q.popleft()

        for k in d:
            nx = x + k[0]
            ny = y + k[1]

            if 0 <= nx < row and 0 <= ny < col and not visited[nx][ny]:  # map 밖으로 나가지 않고 탐색하지 않은경우
                visited[nx][ny] = True
                if cheese_map[nx][ny] == 0:
                    q.append([nx, ny])
                elif cheese_map[nx][ny] == 1:
                    cheese_map[nx][ny] = 0
                    cnt += 1
    return cnt


while True:
    cheese_cnt = cheese_bfs(0, 0)
    melt_time += 1

    if cheese_cnt == 0:
        melt_time -=1
        break

    cheese_arr.append(cheese_cnt)

# 출력부 - 치즈가 모두 녹아서 없어 지는데 걸리는 시간 / 모두 녹기 한시간 전에 남은 치즈 조각 수
print(melt_time)
print(cheese_arr[-1])
