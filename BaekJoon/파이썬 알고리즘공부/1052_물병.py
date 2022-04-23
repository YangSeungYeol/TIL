# 양승열
# 입력부
n, k = map(int, input().split())
ans = 0
if n > k:
    while True:
        cnt = 0
        tmp = n
        while tmp > 0:
            cnt += tmp % 2
            tmp //= 2

        if cnt <= k:
            break

        ans += 1
        n += 1
    print(ans)
else:
    print(0)
