n = int(input())               # n : 기둥의 갯수 1< n <1000
arr = [[0]*2 for _ in range(n)]

max_height = 0
area_total = 0


def area_sum(array):
    now_height = array[0][1]
    area_tot = 0

    for i in range(n):
        if array[i][1] == max_height:
            return area_tot

        area_tot += abs(array[i + 1][0] - array[i][0]) * now_height

        if now_height < array[i+1][1]:
            now_height = array[i+1][1]

    return area_tot


for i in range(n):
    arr[i] = list(map(int, input().split()))

left_arr = sorted(arr)
right_arr = sorted(arr, reverse=True)

for i in range(n):
    if max_height < int(arr[i][1]):
        max_height = int(arr[i][1])

for i in left_arr:
    if i[1] == max_height:
        max_start_idx = i[0]
        break

for i in right_arr:
    if i[1] == max_height:
        max_end_idx = i[0]
        break

area_total += area_sum(left_arr)
area_total += area_sum(right_arr)
area_total += (max_end_idx - max_start_idx + 1) * max_height

print(area_total)
