# # 양승열
# # 입력부
# str1 = input()
# str2 = input()
# while True:
#     if str1.find(str2) < 0:
#         break
#     str1 = str1.replace(str2, '')
# if str1 == '':
#     print("FRULA")
# else:
#     print(str1)

# str1 = input()
# str2 = input()
# stack = ""
# len_str1 = len(str1)
# len_str2 = len(str2)
# if len(str2) == 1:
#     for i in range(len_str1):
#         if str1[i] != str2:
#             stack += str1[i]
# else:
#     for i in range(len_str1):
#         stack += str1[i]
#         if stack[-1] == str2[-1] and stack[-len_str2:] == str2:
#             stack = stack[:-len_str2]
#
# if not len(stack):
#     print("FRULA")
# else:
#     print(stack)

str1 = input()
str2 = input()
stack = []
len_str1 = len(str1)
len_str2 = len(str2)

for i in range(len_str1):
    stack.append(str1[i])
    if stack[-1] == str2[-1] and ''.join(stack[-len_str2:]) == str2:
        del stack[-len_str2:]

ans_str = ''.join(stack)

if ans_str == '':
    print("FRULA")
else:
    print(ans_str)