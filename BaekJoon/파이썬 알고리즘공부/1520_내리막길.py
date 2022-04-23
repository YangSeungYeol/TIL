# # 양승열 - dfs 시간초과
# # 입력부
# m, n = map(int, input().split())
# route = [list(map(int, input().split())) for _ in range(m)]
# dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
# route_cnt = 0
#
#
# def dfs(x, y):
#     global route_cnt
#     if x == m - 1 and y == n - 1:
#         route_cnt += 1
#         return
#     for d in dir:
#         nx = x + d[0]
#         ny = y + d[1]
#         if 0 <= nx < m and 0 <= ny < n and route[x][y] > route[nx][ny]:
#             dfs(nx, ny)
#
#
# dfs(0, 0)
# print(route_cnt)

# 참고 : https://velog.io/@nathan29849/BAEKJOON-1520-%EB%82%B4%EB%A6%AC%EB%A7%89-%EA%B8%B8-DFS-BFS-python
from heapq import heappush, heappop, heapify
m, n = map(int, input().split())
route = [list(map(int, input().split())) for _ in range(m)]
dir = [[-1, 0], [1, 0], [0, -1], [0, 1]]
visited = [[0]*n for _ in range(m)]
count = 0


def bfs(now, x, y):
    q = []
    heapify(q)
    global count
    global route
    global visited
    visited[x][y] = 1
    heappush(q, (-now, x, y))
    while q:
        now, x, y = heappop(q)
        now *= -1
        if x == m-1 and y == n-1:
            continue
        for d in dir:
            nx = x + d[0]
            ny = y + d[1]
            if 0 <= nx < m and 0 <= ny < n:
                temp = route[nx][ny]
                if temp < now:    # 더 낮은 계단칸
                    if visited[nx][ny] == 0:
                        heappush(q, (-temp, nx, ny))
                    visited[nx][ny] += visited[x][y]
    return


bfs(route[0][0], 0, 0)
print(visited[m-1][n-1])
