# 양승열
# Stack
# 입력부
n = int(input())
building_list = list(map(int, input().split()))

stack = []
ans_list = [0 for _ in range(n)]

for i in range(len(building_list)-1, -1, -1):
    if not stack:
        stack.append((i, building_list[i]))
    else:
        while building_list[i] > stack[len(stack)-1][1]:
            ans_idx = stack.pop()
            ans_list[ans_idx[0]] = i + 1
            if not stack:
                break

        stack.append((i, building_list[i]))

for ans in ans_list:
    print(ans, end=" ")


