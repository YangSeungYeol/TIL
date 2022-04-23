# # 양승열
# # 입력부
# t = int(input())
# for _ in range(t):
#     n = int(input())
#     num_list = list(map(int, input().split()))
#     buy_list = []
#     sell_list = []
#     for i in range(n-1):
#         selling_point = False
#         # 매도 포인트 체크
#         for j in range(i+1, n):
#             if num_list[i] < num_list[j]:
#                 selling_point = True
#                 break
#         if selling_point:
#             buy_list.append(num_list[i])
#         else:
#             sell_list.append(num_list[i])

# 양승열
# 입력부
t = int(input())
for _ in range(t):
    n = int(input())
    num_list = list(map(int, input().split()))
    max_price = num_list[n-1]
    profit = 0
    for i in range(n-1, -1, -1):
        if num_list[i] > max_price:
            max_price = num_list[i]
        elif num_list[i] < max_price:
            profit += (max_price - num_list[i])
        else:
            continue
    print(profit)

