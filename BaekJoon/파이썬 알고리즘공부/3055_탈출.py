# 양승열
from collections import deque

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

# 입력부
r, c = map(int, input().split())

tw_map = [list(input()) for _ in range(r)]
visited = [[False] * c for _ in range(r)]

hedgehog = deque()
water = deque()

minute_cnt = 0

# 물, 돌, 고슴도치 위치 세팅 / 방문여부 True 지정
for i in range(r):
    for j in range(c):
        if tw_map[i][j] == '*':
            water.append((i, j))
            visited[i][j] = True
        elif tw_map[i][j] == 'X':
            visited[i][j] = True
        elif tw_map[i][j] == 'S':
            hedgehog.append((i, j))
            visited[i][j] = True

while hedgehog:
    for _ in range(len(water)):
        x, y = water.popleft()
        for d in dir:
            nx = x + d[0]
            ny = y + d[1]
            if 0 <= nx < r and 0 <= ny < c:
                if tw_map[nx][ny] == '.':
                    water.append((nx, ny))
                    tw_map[nx][ny] = '*'
                    visited[nx][ny] = True

    for _ in range(len(hedgehog)):
        x, y = hedgehog.popleft()
        for d in dir:
            nx = x + d[0]
            ny = y + d[1]
            if 0 <= nx < r and 0 <= ny < c:
                if tw_map[nx][ny] == '.' and not visited[nx][ny]:
                    hedgehog.append((nx, ny))
                    tw_map[nx][ny] = '*'
                    visited[nx][ny] = True
                elif tw_map[nx][ny] == 'D':
                    minute_cnt += 1
                    print(minute_cnt)
                    exit()
    minute_cnt += 1
print('KAKTUS')
