# 양승열
from collections import deque

# 입력부
m, n, h = map(int, input().split())
tomato_map = [[list(map(int, input().split())) for _ in range(n)] for _ in range(h)]

dir = [[1, 0, 0], [0, 1, 0], [0, 0, 1], [-1, 0, 0], [0, -1, 0], [0, 0, -1]]
visited = [[[False] * m for _ in range(n)] for _ in range(h)]
q = deque()
raw_tomato = False
ripe_days = 0


# tomato_map[n][m][h]
# 하루에 한칸씩 익힐 수 있음.
# 시간이 흘러 전체가 다 익는다      -> <익는 일수> 출력
# 처음 부터 다 익은 상태           ->  0 출력
# 시간이 흘러도 다 익힐 수 없는 상태 -> -1 출력
def tomato_bfs():
    while q:
        z, x, y = q.popleft()
        visited[z][x][y] = True

        for d in dir:
            nx = x + d[0]
            ny = y + d[1]
            nz = z + d[2]

            if 0 <= nx < n and 0 <= ny < m and 0 <= nz < h and not visited[nz][nx][ny]:  # map 밖으로 나가지 않고 탐색하지 않은 경우
                if tomato_map[nz][nx][ny] == 0:
                    visited[nz][nx][ny] = True
                    tomato_map[nz][nx][ny] = tomato_map[z][x][y] + 1
                    q.append([nz, nx, ny])


for u in tomato_map:
    for v in u:
        if 0 in v:
            raw_tomato = True
            break

# 출력부1 : 이미 다 익은 상태인 경우 0 출력 후 exit / 아니면 bfs 연산 진행
if not raw_tomato:
    print(0)
    exit()
else:
    for k in range(h):
        for i in range(n):
            for j in range(m):
                if tomato_map[k][i][j] == 1:
                    q.append([k, i, j])
    tomato_bfs()

# 출력부2 : 안익은 토마토 있는 경우
for p in tomato_map:
    for q in p:
        for r in q:
            if r == 0:
                print(-1)
                exit()
            ripe_days = max(ripe_days, r)

# 출력부3 : 익힐 토마토 있는 상태로 다 익힌 경우
print(ripe_days-1)
