# 양승열
import sys

start_team = []
link_team = []
min_diff = float('inf')

# 입력부
N = int(input())
ability = [list(map(int, input().split())) for _ in range(N)]


def ability_gap():
    global min_diff
    start = 0
    link = 0
    for i in range(N//2):
        for j in range(N//2):
            if i == j:
                continue
            start += ability[start_team[i]][start_team[j]]
            link += ability[link_team[i]][link_team[j]]
    diff = abs(link - start)
    if diff < min_diff:
        min_diff = diff


def make_team(idx):
    if idx == N:
        if len(start_team) == N//2 and len(link_team) == N//2:
            ability_gap()
        return
    start_team.append(idx)
    make_team(idx + 1)
    start_team.pop()
    link_team.append(idx)
    make_team(idx + 1)
    link_team.pop()


make_team(0)
print(min_diff)
