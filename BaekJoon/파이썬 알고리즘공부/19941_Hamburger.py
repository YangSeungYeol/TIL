n, k = map(int, input().split())    # n : 식탁의 길이 / k : 햄버거를 선택할 수 있는 거리

strList = map(str, input())

listPh = list(strList)

# print(listPh)

cnt = 0

for i in range(n):
    if listPh[i] == "P":
        for j in range(-k, k+1):
            if 0 <= i+j < n:    # list index out of range 방지
                if listPh[i+j] == "H":
                    listPh[i+j] = "E"
                    cnt += 1
                    break
print(cnt)