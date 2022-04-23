# 양승열
from collections import deque

time = 0
# 입력부
n, k = map(int, input().split())
visited = [[False] for _ in range(100001)]


def bfs(x, dst):
    global time
    q = deque()
    q.append(x)
    while True:
        length = len(q)
        print(length)
        for _ in range(length):
            x = q.popleft()
            if x == dst:
                return time
            if 0 <= x - 1 and not visited[x - 1]:
                q.append(x - 1)
                visited[x - 1] = True
            if x + 1 <= 100000 and not visited[x + 1]:
                q.append(x + 1)
                visited[x + 1] = True
            if 2 * x <= 100000 and not visited[2 * x]:
                q.append(2 * x)
                visited[2 * x] = True
        time += 1


print(bfs(n, k))
