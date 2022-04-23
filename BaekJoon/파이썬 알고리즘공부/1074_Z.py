# 양승열
# 입력부
n, r, c = map(int, input().split())
num = 0


def z_recusion(n, r, c):
    half_n = 2 ** (n - 1)
    if n == 1:
        return 2 * r + c

    if r < half_n and c < half_n:  # 좌상단
        return z_recusion(n - 1, r, c)
    elif r < half_n <= c:  # 우상단
        return 1 * half_n ** 2 + z_recusion(n - 1, r, c - half_n)
    elif c < half_n <= r:  # 좌하단
        return 2 * half_n ** 2 + z_recusion(n - 1, r - half_n, c)
    elif r >= half_n and c >= half_n:  # 우하단
        return 3 * half_n ** 2 + z_recusion(n - 1, r - half_n, c - half_n)


print(z_recusion(n, r, c))
