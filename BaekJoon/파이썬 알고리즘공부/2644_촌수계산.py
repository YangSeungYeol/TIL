# 양승열
# 입력부
n = int(input())
p1, p2 = map(int, input().split())
m = int(input())


def dfs(x, y):
    if x == y:
        print(kinship[y])
        exit()

    visited[x] = True
    for i in graph[x]:
        if not visited[i]:
            kinship[i] = kinship[x] + 1
            dfs(i, y)
    return False


graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)
kinship = [0] * (n+1)
for _ in range(m):
    p, c = map(int, input().split())
    graph[p].append(c)
    graph[c].append(p)

if not dfs(p1, p2):
    print(-1)
