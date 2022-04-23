# 양승열
peoples = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
upper_ladder = []
lower_ladder = []
ans_ladder = ""
# 입력부
k = int(input())  # 참가한 사람 수
n = int(input())  # 사다리 가로줄 수
final_order = input()  # 사다리 타고 난 후 최종 순서
start_order = peoples[:k]  # 참가한 사람 사다리 시작 순서
ladder_status = []
slice_value = ""
for i in range(k-1):  # 리스트 자르는 기준 값 (?행)
    slice_value += "?"
    ans_ladder += "*"  # ? 줄에 들어갈 사다리 초기화

for _ in range(n):
    ladder_status.append(input())

upper_ladder = ladder_status[:ladder_status.index(slice_value)]
lower_ladder = list(reversed(ladder_status[ladder_status.index(slice_value) + 1:]))

for ladder in upper_ladder:
    for i in range(len(ladder)):
        if ladder[i] == '-':
            start_order = start_order.replace(start_order[i], '@').replace(start_order[i+1], start_order[i]).replace('@', start_order[i+1])
            # start_order = start_order.replace(start_order[i], start_order[i+1]).replace(start_order[i+1], start_order[i])
print(start_order)

for ladder in lower_ladder:
    for i in range(len(ladder)):
        if ladder[i] == '-':
            final_order = final_order.replace(final_order[i], '@').replace(final_order[i+1], final_order[i]).replace('@', final_order[i+1])

print(start_order)
print(final_order)
for i in range(k-1):
    if start_order[i] == final_order[i+1] and start_order[i+1] == final_order[i]:
        ans_ladder = ans_ladder[:i] + '-' + ans_ladder[i+1:]
        start_order = start_order.replace(start_order[i], '@').replace(start_order[i+1], start_order[i]).replace('@', start_order[i+1])

if start_order != final_order:
    ans_ladder = ""
    for _ in range(k-1):
        ans_ladder += 'x'
print(ans_ladder)



