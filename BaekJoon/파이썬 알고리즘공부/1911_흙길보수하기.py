# 양승열
# 입력부
N, L = map(int, input().split())
pool_list = [list(map(int, input().split())) for _ in range(N)]
pool_list.sort()
# print(pool_list)
plank_cnt = 0
now_pos = 0
for i in range(len(pool_list)):
    if now_pos < pool_list[i][0]:
        now_pos = pool_list[i][0] - 1
    while pool_list[i][1] - 1 > now_pos:  # 현재위치가 웅덩이 마지막위치보다 커질때까지
        now_pos += L
        plank_cnt += 1
print(plank_cnt)
