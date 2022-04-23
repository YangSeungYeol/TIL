# 양승열
# 입력부
arr_map = [list(map(int, input().split())) for _ in range(19)]


def chk_result(x, y):
    color = arr_map[x][y]

    # → 으로 오목
    right_cnt = 1
    k = 1
    while True:
        nx, ny = x, y + k
        if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
            break
        if color == arr_map[nx][ny]:
            right_cnt += 1
        else:
            break
        k += 1

    # 첫번째 돌의 이전돌 체크 (6목여부)
    xx, yy = x, y - 1
    if right_cnt == 5:
        if 0 <= xx < 19 and 0 <= yy < 19:
            if arr_map[xx][yy] == color:
                return False
        return True

    # ↓ 으로 오목
    down_cnt = 1
    k = 1
    while True:
        nx, ny = x + k, y
        if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
            break
        if color == arr_map[nx][ny]:
            down_cnt += 1
        else:
            break
        k += 1

    # 첫번째 돌의 이전돌 체크 (6목여부)
    xx, yy = x - 1, y
    if down_cnt == 5:
        if 0 <= xx < 19 and 0 <= yy < 19:
            if arr_map[xx][yy] == color:
                return False
        return True

    # ↘ 으로 오목
    right_down_cnt = 1
    k = 1
    while True:
        nx, ny = x + k, y + k
        if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
            break
        if color == arr_map[nx][ny]:
            right_down_cnt += 1
        else:
            break
        k += 1

    # 첫번째 돌의 이전돌 체크 (6목여부)
    xx, yy = x - 1, y - 1
    if right_down_cnt == 5:
        if 0 <= xx < 19 and 0 <= yy < 19:
            if arr_map[xx][yy] == color:
                return False
        return True

    # ↗ 으로 오목
    right_up_cnt = 1
    k = 1
    while True:
        nx, ny = x - k, y + k
        if nx < 0 or nx >= 19 or ny < 0 or ny >= 19:
            break
        if color == arr_map[nx][ny]:
            right_up_cnt += 1
        else:
            break
        k += 1

    # 첫번째 돌의 이전돌 체크 (6목여부)
    xx, yy = x + 1, y - 1
    if right_up_cnt == 5:
        if 0 <= xx < 19 and 0 <= yy < 19:
            if arr_map[xx][yy] == color:
                return False
        return True


game_end = False
for i in range(19):
    for j in range(19):
        if arr_map[i][j] != 0:
            if chk_result(i, j):
                print(arr_map[i][j])
                print(i + 1, j + 1)
                game_end = True

if not game_end:
    print(0)
