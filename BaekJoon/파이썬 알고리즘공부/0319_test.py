from collections import deque

lst = [1, 2, 3, 4, 5]

q = deque()
for _ in range(len(lst)):
    x = lst.pop(0)
    print(len(lst))
