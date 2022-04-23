# 양승열
# 입력부
# n : 세로선 개수 / m : 가로선 개수 / h : 가로선 놓을 수 있는 위치의 개수
n, m, h = map(int, input().split())
ladder = [[0] * n for _ in range(h)]
if not m:
    print(0)
    exit()
for _ in range(m):
    a, b = map(int, input().split())
    ladder[a-1][b-1] = 1

for i in ladder:  # ladder[x][y] == 1 우로 이동 / ladder[x][y-1] == 1 좌로 이동
    print(i, end='\n')

for i in range(h):
    for j in range(n):
        x, y = 0, j
