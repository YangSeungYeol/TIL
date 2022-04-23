# 양승열 -- 시계 반시계 돌릴 때 가로 세로 바꿔 줘야 함!
# 입력부
n, m, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
calc_num = list(map(int, input().split()))


def calc_1():  # 상하 반전
    global arr
    tmp = [[0] * m for _ in range(n)]
    for p in range(n):
        tmp[p] = arr[n - 1 - p]
    arr = tmp


def calc_2():  # 좌우 반전
    global arr
    tmp = [[0] * m for _ in range(n)]
    for p in range(n):
        for q in range(m):
            tmp[p][q] = arr[p][m - 1 - q]
    arr = tmp


def calc_3():  # 시계 방향 90도 회전
    global arr, n, m
    tmp = [[0] * n for _ in range(m)]
    for p in range(m):
        for q in range(n):
            tmp[p][q] = arr[n - 1 - q][p]
    arr = tmp

    n = len(arr)
    m = len(arr[0])


def calc_4():  # 반시계 방향 90도 회전
    global arr, n, m
    tmp = [[0] * n for _ in range(m)]
    for p in range(m):
        for q in range(n):
            tmp[p][q] = arr[q][m - 1 - p]
    arr = tmp

    n = len(arr)
    m = len(arr[0])


def calc_5():  # 쪼갠 덩어리 시계 방향 이동
    global arr
    tmp = [[0] * m for _ in range(n)]
    # 1 -> 2
    for p in range(n//2):
        for q in range(m//2):
            tmp[p][q + m//2] = arr[p][q]
    # 2 -> 3
    for p in range(n//2):
        for q in range(m//2, m):
            tmp[p + n//2][q] = arr[p][q]
    # 3 -> 4
    for p in range(n//2, n):
        for q in range(m//2, m):
            tmp[p][q - m//2] = arr[p][q]
    # 4 -> 1
    for p in range(n//2, n):
        for q in range(m//2):
            tmp[p - n//2][q] = arr[p][q]
    arr = tmp


def calc_6():  # 쪼갠 덩어리 반시계 방향 이동
    global arr
    tmp = [[0] * m for _ in range(n)]
    # 1 -> 4
    for p in range(n//2):
        for q in range(m//2):
            tmp[p + n//2][q] = arr[p][q]
    # 4 -> 3
    for p in range(n//2, n):
        for q in range(m//2):
            tmp[p][q + m//2] = arr[p][q]
    # 3 -> 2
    for p in range(n//2, n):
        for q in range(m//2, m):
            tmp[p - n//2][q] = arr[p][q]
    # 2 -> 1
    for p in range(n//2):
        for q in range(m//2, m):
            tmp[p][q - m//2] = arr[p][q]
    arr = tmp


for i in range(r):
    if calc_num[i] == 1:
        calc_1()
    elif calc_num[i] == 2:
        calc_2()
    elif calc_num[i] == 3:
        calc_3()
    elif calc_num[i] == 4:
        calc_4()
    elif calc_num[i] == 5:
        calc_5()
    elif calc_num[i] == 6:
        calc_6()

for j in range(len(arr)):
    print(*arr[j])
