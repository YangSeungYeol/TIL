# 양승열
# 에라토스테네스의 체
num_list = [True for i in range(1000001)]

for i in range(2, 1001):
    if num_list[i]:  # 소수 인 경우
        for j in range(i + i, 1000001, i):  # 배수들 False 처리 (소수 아님)
            num_list[j] = False

while True:
    # 입력부
    n = int(input())
    if n == 0:
        break

    for i in range(3, len(num_list)):
        if num_list[i] and num_list[n-i]:
            # 출력부
            print(str(n) + " = " + str(i) + " + " + str(n-i))
            break
