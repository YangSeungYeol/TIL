


N = int(input())
towerList = list(map(int, input().rstrip().split()))
resultList = [0 for _ in range(N)]
stack = []

for i in range(len(towerList) - 1, -1, -1):
    if len(stack) == 0:
        stack.append([i, towerList[i]])
    else:
        while towerList[i] > stack[len(stack) - 1][1]:
            tower = stack.pop()
            resultList[tower[0]] = i + 1
            if len(stack) == 0:
                break

        stack.append([i, towerList[i]])

for num in resultList:
    print(num, end=" ")