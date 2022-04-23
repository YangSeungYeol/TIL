# 양승열
from collections import deque


tc = int(input())

move = [[2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2], [1, -2], [2, -1]]


def bfs(x_n, y_n, x_d, y_d):
    q = deque()
    q.append([x_n, y_n])

    while q:
        x_n, y_n = q.popleft()

        if x_n == x_d and y_n == y_d:
            return chess_map[x_dst][y_dst]

        for m in move:
            x_nxt = x_n + m[0]
            y_nxt = y_n + m[1]
            if x_nxt == x_n and y_nxt == y_n:  # 처음 위치로 돌아 가는 경우 제외
                continue

            if 0 <= x_nxt < size and 0 <= y_nxt < size:  # chess_map 밖으로 나가지 않고 탐색하지 않은경우
                if chess_map[x_nxt][y_nxt] == 0:  # 이부분 놓쳐서 계속 실패함..
                    chess_map[x_nxt][y_nxt] = chess_map[x_n][y_n] + 1
                    q.append([x_nxt, y_nxt])


for _ in range(tc):
    size = int(input())
    x_now, y_now = map(int, input().split())
    x_dst, y_dst = map(int, input().split())
    chess_map = [[0] * size for _ in range(size)]
    move_cnt = bfs(x_now, y_now, x_dst, y_dst)

    print(move_cnt)
