# 양승열
# 입력부
n, q = map(int, input().split())
ice_board = [list(map(int, input().split())) for _ in range(2**n)]
L = list(map(int, input().split()))
dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
melt_spot = []
ice_sum = 0
ice_cube = []
visited = [[False] * (2**n) for _ in range(2**n)]


def fire_storm(step):
    # tornado : 배열 90도 돌리기

    # fireball : 얼음 녹이기
    # 3면 이상 0보다 큰값과 인접해 있지 않으면 얼음 양 -1
    for x in range(2**n):
        for y in range(2**n):
            if ice_board[x][y] == 0:
                continue
            cnt = 0
            for d in dir:
                nx = x + d[0]
                ny = y + d[1]

                if 0 <= nx < 2**n and 0 <= ny < 2**n and ice_board[nx][ny]:
                    cnt += 1
            if cnt < 3:
                melt_spot.append([x, y])
    print(ice_board)
    for lst in melt_spot:
        ice_board[int(lst[0])][int(lst[1])] -= 1


for i in range(2**n):
    ice_sum += sum(ice_board[i])

# 얼음 가장 큰 덩어리 차지하는 칸 개수 구하기
for i in range(2**n):
    for j in range(2**n):
        temp = []
        if ice_board[i][j] != 0 and not visited[i][j]:
            temp.append([i, j])
            visited[i][j] = True
            cnt1 = 1
            while temp:
                ice = temp.pop()
                ii = ice[0]
                jj = ice[1]
                for di in dir:
                    ni, nj = ii + di[0], jj + di[1]
                    if 0 <= ni < 2**n and 0 <= nj < 2**n and ice_board[ni][nj] and not visited[ni][nj]:
                        temp.append([ni, nj])
                        visited[ni][nj] = True
                        ice_sum += ice_board[ni][nj]
                        cnt1 += 1
            ice_cube.append(cnt1)

