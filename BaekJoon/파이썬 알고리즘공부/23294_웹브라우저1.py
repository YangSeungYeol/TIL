# 양승열
# 입력부
# n : 웹 페이지 개수 / q : 작업의 개수 / c : 최대 캐시 용량
import sys

n, q, c = map(int, input().split())
# cap의 idx는 웹페이지의 번호 / value는 idx번째 웹페이지를 방문할때 사용하는 캐시크기
cap = list(map(int, input().split()))
back_space = []
front_space = []
now_page = 0
cache_volume = 0


def back_ward():
    global now_page
    if back_space:
        front_space.append(now_page)
        now_page = back_space[-1]
        back_space.pop(-1)


def front_ward():
    global now_page
    if front_space:
        back_space.append(now_page)
        now_page = front_space[-1]
        front_space.pop(-1)


def access(page):
    global now_page
    front_space.clear()
    if now_page:
        back_space.append(now_page)
    now_page = page
    volume_check()
    while cache_volume > c and back_space:
        back_space.pop(0)
        volume_check()


def compress():
    i = 0
    if len(back_space) < 2:
        return
    while True:
        if i == len(back_space) - 1:
            break
        if back_space[i] == back_space[i+1]:
            back_space.pop(i)
            i -= 1
        i += 1


def volume_check():
    global cache_volume
    sum_front = 0
    sum_back = 0
    for idx in front_space:
        sum_front += cap[idx - 1]
    for idx in back_space:
        sum_back += cap[idx - 1]
    cache_volume = sum_front + sum_back + cap[now_page - 1]


for _ in range(q):
    line = sys.stdin.readline().strip().split()
    if len(line) == 1:
        if line[0] == "B":
            back_ward()
        elif line[0] == "F":
            front_ward()
        elif line[0] == "C":
            compress()
    else:
        access(int(line[1]))

print(now_page)

if back_space:
    while len(back_space):
        print(back_space.pop(-1), end=' ')
    print()
else:
    print(-1)

if front_space:
    while len(front_space):
        print(front_space.pop(-1), end=' ')
    print()
else:
    print(-1)
