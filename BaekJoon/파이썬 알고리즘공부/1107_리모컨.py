# 양승열
near_num = float('inf')
# 입력부
# case1) (더 큰 채널 중에 제일 가까운 수) + (-버튼 누르는 수)
# case2) (더 작은 채널 중에 제일 가까운 수) + (+버튼 누르는 수)
# case1, 2 중 더 작은 값 채택
# 숫자를 이어 붙이며 탐색해야하므로 스트링으로 받자
n = int(input())
m = int(input())
if m:
    not_work = list(map(str, input().split()))


def press_cnt(num):
    global near_num
    for i in range(10):
        str_i = str(i)
        if str_i not in not_work:
            tmp_num = num + str_i
            near_num = min(near_num, abs(n - int(tmp_num)) + len(tmp_num))

            if len(tmp_num) < 6:
                print(tmp_num)
                press_cnt(tmp_num)


# 출력부
near_num = min(near_num, abs(100 - n))  # 101 0 case 1,0,1 입력보다 + 한번이 빠름

if n == 100:
    print(0)
    exit()

if m:
    press_cnt("")
else:
    near_num = min(near_num, len(str(n)))

print(near_num)
