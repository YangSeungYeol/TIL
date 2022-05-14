# 양승열 --> 최소신장트리 유형인지못함 + 알고리즘 까먹음.. 어케푸는건지 모르겠음..
# 크루스칼 / 프림
# 출처 : https://joey09.tistory.com/66 (크루스칼)
import heapq

# 입력부
n = int(input())
stars_pos = [list(map(float, input().split())) for _ in range(n)]

edges = []
parents = [i for i in range(n+2)]


def find(x, parent):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x], parent)
    return parent[x]


def uni(x, y, parent):
    x = find(x, parent)
    y = find(y, parent)
    if x == y:
        return
    parent[y] = x
    return


for i in range(len(stars_pos)):
    for j in range(len(stars_pos)):
        if i == j:
            continue
        p1 = stars_pos[i]
        p2 = stars_pos[j]
        w = round(((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5, 2)
        heapq.heappush(edges, (w, p1, p2, i, j))

answer = 0

while edges:
    w, s, e, i, j = heapq.heappop(edges)
    if find(i, parents) != find(j, parents):
        uni(i, j, parents)
        answer += w

print(answer)
