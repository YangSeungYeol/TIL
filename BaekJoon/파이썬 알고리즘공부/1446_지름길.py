# 양승열
distance = float('inf')
# 입력부
n, d = map(int, input().split())
# shortcut_list[idx][0] == 지름길 시작 위치
# shortcut_list[idx][1] == 지름길 도착 위치
# shortcut_list[idx][2] == 지름길 길이
shortcut_list = []
for i in range(n):
    start, end, shortcut = map(int, input().split())
    if (end <= d) and ((end-start) > shortcut):
        shortcut_list.append((start, end, shortcut))
shortcut_list.sort()


# 첫번째 지름길까지는 도착점 - 출발점
# dfs 돌면서 시작 위치가 지름길 리스트 시작 위치에 포함인 경우 도착 위치를 확인
# 도착 위치가 고속도로 길이 보다 작으면 nxt 시작 위치를 지름길 도착 위치로
# 당장의 지름길을 안타는게 이득일수도 있음 탄경우/안탄경우 다 돌려서 더 작은값 채택
def dfs(x, idx, dis):
    global distance
    if idx == len(shortcut_list):  # 지름길 다쓰면 남은거리 더하고 리턴
        dis += (d - x)
        if dis < distance:
            distance = dis
        return
    a, b, c = shortcut_list[idx]
    if x > a:  # 지름길 안타는 경우
        dfs(x, idx + 1, dis)
    elif x <= a:  # 지름길 타는 경우
        dfs(b, idx + 1, dis + (a - x) + c)
        dfs(x, idx + 1, dis)


dfs(0, 0, 0)

print(distance)
