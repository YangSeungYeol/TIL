# 양승열
# 출처 : https://hose0728.tistory.com/66
# 입력부
import sys

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

n, m, k = map(int, sys.stdin.readline().split())
sharks = [[0, 0] for _ in range(m)]
board = []
smell = {}

for p in range(n):
    lst = list(map(int, sys.stdin.readline().split()))
    board.append(lst)

    for q in range(n):
        if lst[q]:
            sharks[lst[q] - 1] = [p, q]
            smell[(p, q)] = [0, lst[q] - 1]

direction = list(map(int, sys.stdin.readline().split()))
dir_list = [list(map(int, sys.stdin.readline().split())) for _ in range(4 * m)]


def solution(board, smell, sharks, direction, dir_list):
    time = 0
    cnt = m
    while True:  # 1000초까지 1초씩 증가 하면서 무한 루프, 넘으면 -1 리턴 후 종료
        time += 1
        if time > 1000:
            return -1
        for i in range(m):
            if sharks[i][0] == -1:  # 격자 밖으로 쫒겨난 상어는 패스
                continue
            else:
                x, y = sharks[i]
                flag = 1
                d = direction[i]  # 현재 상어가 보는 방향
                d_list = dir_list[4 * i + d - 1]

                for dl in d_list:
                    nx, ny = x + dir[dl - 1][0], y + dir[dl - 1][1]
                    if 0 <= nx < n and 0 <= ny < n:
                        if smell.get((nx, ny)) is None or time - smell[(nx, ny)][0] > k:
                            flag = 0

                            if board[nx][ny]:  # 가려는 칸에 다른 상어가 있다면
                                cnt -= 1
                                if cnt == 1:
                                    return time
                                if board[nx][ny] > i + 1:  # 현재 상어가 더 강할 때
                                    sharks[board[nx][ny] - 1][0] = -1
                                    board[nx][ny] = i + 1
                                    direction[i] = dl
                                    sharks[i][0], sharks[i][1] = nx, ny
                                else:  # 현재 상어가 더 약할 때
                                    sharks[i][0] = -1
                            else:  # 가려는 칸에 다른 상어가 없다면
                                sharks[i][0], sharks[i][1] = nx, ny
                                board[nx][ny] = i + 1
                                direction[i] = dl
                            board[x][y] = 0
                            break

                if flag:  # 4방향 모두 냄새가 남아 있는 경우
                    for dl in d_list:
                        nx, ny = x + dir[dl - 1][0], y + dir[dl - 1][1]
                        if 0 <= nx < n and 0 <= ny < n and smell[(nx, ny)][1] == i:
                            direction[i] = dl
                            board[nx][ny] = i + 1
                            board[x][y] = 0
                            sharks[i][0], sharks[i][1] = nx, ny
                            break
        for j in range(m):
            if sharks[j][0] == -1:
                continue
            else:
                smell[(sharks[j][0], sharks[j][1])] = [time, j]


ans = solution(board, smell, sharks, direction, dir_list)
print(ans)
