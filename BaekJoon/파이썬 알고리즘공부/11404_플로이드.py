# 양승열

max_cost = 100001

# 입력부 n = 도시의 개수 / m = 버스의 개수 / a = 시작 도시, b = 도착 도시, c = 1회 탑승 비용
n = int(input())
m = int(input())
floyd = [[max_cost]*n for _ in range(n)]

# 시작 도시 = 도착 도시 0처리
for i in range(n):
    floyd[i][i] = 0

# 입력값 배열 세팅 - 시작 도시와 도착 도시를 연결 하는 노선은 하나가 아닐 수 있기 때문에 min() 사용
for _ in range(m):
    a, b, c = map(int, input().split())
    floyd[a-1][b-1] = min(floyd[a-1][b-1], c)

# Floyd Algorithm
for i in range(n):
    for j in range(n):
        for k in range(n):
            floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k])  # i를 거칠 때와 아닐때 비교해 더 짧은 거리 채택

# 출력부 - 이렇게 하면 98%에서 오류,,, 원인이 뭘까요?
for i in floyd:
    for j in i:
        if j == max_cost:
            j = 0
        print(j, end=' ')
    print()
