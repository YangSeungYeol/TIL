sudoku = [list(map(int, input().split())) for _ in range(9)]
chk_row = [[False] * 10 for _ in range(10)]  # 행에 숫자(1~9)가 존재하는지 여부 확인
chk_col = [[False] * 10 for _ in range(10)]  # 열에 숫자(1~9)가 존재하는지 여부 확인
chk_square = [[False] * 10 for _ in range(10)]  # 정사각형(3x3)에 숫자(1~9)가 존재하는지 여부 확인


def square(x, y):
    return (x // 3) * 3 + (y // 3)


def make_sudoku(z):
    if z == 81:
        for i in range(9):
            print(*sudoku[i])
        exit(0)
    x = z // 9
    y = z % 9

    if sudoku[x][y]:
        make_sudoku(z + 1)
    else:
        for i in range(1, 10):  # 0인 위치에 들어갈 숫자 찾기
            #  해당 열, 행, 정사각형 안에 i가 없으면 i를 넣는다
            if chk_row[x][i] == 0 and chk_col[y][i] == 0 and chk_square[square(x, y)][i] == 0:
                chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = True
                sudoku[x][y] = i
                make_sudoku(z + 1)
                # 숫자 i가 아니면 백트래킹
                sudoku[x][y] = 0
                chk_row[x][i] = chk_col[y][i] = chk_square[square(x, y)][i] = False


for i in range(9):
    for j in range(9):
        if sudoku[i][j]:
            chk_row[i][sudoku[i][j]] = True
            chk_col[j][sudoku[i][j]] = True
            chk_square[square(i, j)][sudoku[i][j]] = True

make_sudoku(0)
