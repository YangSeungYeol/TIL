# 양승열
import sys

T = int(input())

for _ in range(T):
    exec_list = []
    num_list = []
    reverse = False
    error_flag = False
    p = input()
    for i in p:
        exec_list.append(i)
    n = int(input())
    # num_list = list(map(int, input().rstrip()[1:-1].split(",")))
    num_list = list(sys.stdin.readline().rstrip()[1:-1].split(","))
    if num_list == ['']:
        num_list = []
    for ex in exec_list:
        if ex == 'R':
            reverse = not reverse
        elif ex == 'D' and num_list:
            if reverse:
                num_list.pop()
            else:
                num_list.pop(0)
        elif ex == 'D' and not num_list:
            error_flag = True
            break
    # if error_flag:
    #     print("error")
    # elif num_list:
    #     print(list(map(int, num_list)))
    # elif num_list and reverse:
    #     num_list.reverse()
    #     print(list(map(int, num_list)))
    # else:
    #     continue
    if error_flag:
        print("error")
    elif num_list and not reverse:
        print("[" + ",".join(num_list) + "]")
    elif num_list and reverse:
        num_list.reverse()
        print("[" + ",".join(num_list) + "]")
    else:
        print(num_list)
