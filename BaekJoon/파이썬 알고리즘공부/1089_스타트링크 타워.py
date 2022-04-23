# 양승열
# 입력부
num_list = [[[1], [1, 4], []], [[1, 2, 3, 7], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [5, 6]], [[1, 7], [0, 1, 7], []], [[1, 3, 4, 5, 7, 9], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9], [2]], [[1, 4, 7], [1, 4, 7], []]]

n = int(input())
nn = 4*n-1
floor_num = [[] for _ in range(5)]
all_num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
impossible_num = set()
possible_each_digit = [[] for _ in range(n)]
print(possible_each_digit)

for i in range(5):
    bulb_num = input()
    floor_num[i].extend(bulb_num)
print(floor_num)

for c in range(0, nn, 4):
    for i in range(5):
        for j in range(c, c + 3):
            if floor_num[i][j] == '#':
                for k in num_list[i][j - c]:
                    impossible_num.add(k)
    possible_num = all_num - impossible_num
    while True:
        if not possible_num:
            break
        possible_each_digit[c//4].append(possible_num.pop())
    print(possible_each_digit)
    impossible_num.clear()
if possible_each_digit == [[]]:
    print(-1)
    exit()

digit = 0
floor_sum = 0
length = len(possible_each_digit)
# for i in reversed(possible_each_digit):
#     a = 1
#     for j in range(length - 1, -1, -1):
#         print('####', i)
#         print('####', possible_each_digit[j])
#         if i == possible_each_digit[j]:
#             continue
#         print(len(possible_each_digit[j]))
#         a *= len(possible_each_digit[j])
#     print(10**digit, a, sum(i))
#
#     floor_sum += 10**digit * a * sum(i)
#
#     digit += 1

for i in range(length - 1, -1, -1):
    a = 1
    for j in range(length - 1, -1, -1):
        if i == j:
            continue
        print(len(possible_each_digit[j]))
        a *= len(possible_each_digit[j])
    print(10**digit, a, sum(possible_each_digit[i]))

    floor_sum += 10**digit * a * sum(possible_each_digit[i])

    digit += 1

b = 1
for i in possible_each_digit:
    b *= len(i)
print(b)
floor_avg = floor_sum/b
print(floor_avg)


