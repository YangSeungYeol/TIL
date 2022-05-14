n = int(input())
total = 0
col = [0] * n

def chk(level):
    for i in range(level):
        # 대각선 or 같은 라인 여부 체크 / col[i]가 X좌표, i가 Y좌표를 의미.
        if col[i] == col[level] or abs(col[level] - col[i]) == level - i:
            return False
    return True


def nqueen(x):
    global total

    if x == n:
        total += 1
    else:
        for i in range(n):
            col[x] = i  # 해당 위치에 퀸을 배치
            if chk(x):  # 참이면 다음 행의 퀸 배치, 아니면 다른 위치로 퀸 배치 변경
                nqueen(x + 1)


nqueen(0)
print(total)