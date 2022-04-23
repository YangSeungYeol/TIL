# 양승열
# 입력부
n, m, r = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

for j in range(min(n, m) // 2):
    mod_r = r % (2*n+2*m-4-8*j)
    for i in range(mod_r):
        x, y = j, j
        temp = arr[x][y]

        for k in range(j + 1, n - j):        # 좌
            x = k
            nxt_val = arr[x][y]
            arr[x][y] = temp
            temp = nxt_val

        for k in range(j + 1, m - j):        # 하
            y = k
            nxt_val = arr[x][y]
            arr[x][y] = temp
            temp = nxt_val

        for k in range(j + 1, n - j):        # 우
            x = n - k - 1
            nxt_val = arr[x][y]
            arr[x][y] = temp
            temp = nxt_val

        for k in range(j + 1, m - j):        # 상
            y = m - k - 1
            nxt_val = arr[x][y]
            arr[x][y] = temp
            temp = nxt_val

# 출력부
for i in range(n):
    for j in range(m):
        print(arr[i][j], end=' ')
    print()
