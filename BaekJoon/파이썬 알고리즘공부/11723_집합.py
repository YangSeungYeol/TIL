# 양승열
import sys
arr_s = []

# 입력부
m = int(sys.stdin.readline())
line = []
for _ in range(m):
    line.clear()
    line = sys.stdin.readline().strip().split()
    if len(line) == 1:
        if line[0] == "all":
            arr_s = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
        elif line[0] == 'empty':
            arr_s.clear()
    else:
        calc, num = line[0], int(line[1])
        if calc == "add":
            if num not in arr_s:
                arr_s.append(num)
        elif calc == "check":
            chk = False
            for i in range(len(arr_s)):
                if arr_s[i] == num:
                    chk = True
                    break
            if chk:
                print(1)
            else:
                print(0)
        elif calc == "remove":
            if num in arr_s:
                arr_s.remove(num)
        elif calc == "toggle":
            if num in arr_s:
                arr_s.remove(num)
            else:
                arr_s.append(num)
