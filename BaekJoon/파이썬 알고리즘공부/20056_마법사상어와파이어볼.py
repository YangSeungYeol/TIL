# 양승열
dir = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
fire_ball = []
ans_m = 0
# 입력부
N, M, K = map(int, input().split())
for i in range(M):
    r, c, m, s, d = map(int, input().split())
    fire_ball.append([r - 1, c - 1, m, s, d])

arr = [[[] for _ in range(N)] for _ in range(N)]  # 질량/속력/방향을 한 위치가 들고 있어야 함
# arr = [[[]]*N for _ in range(N)]

for k in range(K):
    # 파이어 볼 이동
    while fire_ball:
        nr, nc, nm, ns, nd = fire_ball.pop(0)
        # N번 1번 연결
        nr = (nr + ns * dir[nd][0]) % N
        nc = (nc + ns * dir[nd][1]) % N
        arr[nr][nc].append([nm, ns, nd])
    # 파이어 볼 2개 이상 여부 판단
    for i in range(N):
        for j in range(N):
            sum_m, sum_s = 0, 0
            odd, even = 0, 0
            ball_cnt = len(arr[i][j])

            if ball_cnt > 1:
                # 파이어 볼 합치기
                while arr[i][j]:
                    m, s, d = arr[i][j].pop(0)
                    sum_m += m
                    sum_s += s
                    if d % 2:
                        odd += 1
                    else:
                        even += 1
                if odd == 0 or even == 0:
                    di = [0, 2, 4, 6]
                else:
                    di = [1, 3, 5, 7]
                # 질량 0 소멸 -> 질량 0 아닐 때
                if sum_m // 5:
                    for d in di:
                        fire_ball.append([i, j, sum_m//5, sum_s//ball_cnt, d])
            elif ball_cnt == 1:
                m, s, d = arr[i][j].pop(0)
                fire_ball.append([i, j, m, s, d])

for f in fire_ball:
    ans_m += f[2]

print(ans_m)
