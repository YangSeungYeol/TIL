# 양승열
# 입력부
n = int(input())
# arr = []
arr_rest = []

# n = 0 then 1 / n = 1 then 3 / n = 2 then 7 / n = 3 then 17 n = 4 then 41
# 규칙 : A(n) = 2*A(n-1) + A(n-2)

ans = 0
# arr.append(1)
# arr.append(3)
arr_rest.append(1)
arr_rest.append(3)

# 그냥 계산시 메모리 초과
# for i in range(2, n+1):
#     arr.append(2 * arr[i - 1] + arr[i - 2])
# print(arr[n] % 9901)

for i in range(2, n+1):
    arr_rest.append((2 * arr_rest[i - 1] % 9901 + arr_rest[i - 2] % 9901) % 9901)
print(arr_rest[n])
