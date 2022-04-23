# 양승열
# 입력부
n = int(input())
rank_list = []
point_list = []
dissatisfaction = 0
for i in range(n):
    rank_list.append(int(input()))
    point_list.append(i + 1)
rank_list.sort()

for i in range(n):
    if rank_list[i] == point_list[i]:
        continue
    dissatisfaction += abs(rank_list[i] - point_list[i])
print(dissatisfaction)
