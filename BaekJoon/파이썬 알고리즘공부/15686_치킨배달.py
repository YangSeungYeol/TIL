# 양승열

# 입력부
from itertools import combinations


def distance(hou, chk):
    temp = []
    ans = []
    for k in chk:
        dist = 0
        for h in hou:
            temp.clear()
            for c in k:
                temp.append(abs(c[0] - h[0]) + abs(c[1] - h[1]))
            dist += int(min(temp))
        ans.append(dist)
    return min(ans)


n, m = map(int, input().split())
city_map = [list(map(int, input().split())) for _ in range(n)]
chicken = []
house = []

for i in range(n):
    for j in range(n):
        if city_map[i][j] == 0:
            continue
        if city_map[i][j] == 1:
            house.append([i, j])
        if city_map[i][j] == 2:
            chicken.append([i, j])

combi_list = list(combinations(chicken, m))
print(distance(house, combi_list))
