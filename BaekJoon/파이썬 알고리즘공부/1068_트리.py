# # 양승열
# # 입력부
# n = int(input())
# tree = list(map(int, input().split()))
# remove_node = int(input())
# leaf_nodes = 0
# chk_remove = [False for _ in range(n)]
#
#
# def recursion(node):
#     idx_list = list(filter(lambda x: tree[x] == node, range(len(tree))))
#     print(idx_list)
#     if not idx_list:
#         return
#     for i in idx_list:
#         print(i)
#         chk_remove[i] = True
#         recursion(i)
#
#
# chk_remove[remove_node] = True
# recursion(remove_node)
#
# # leaf_node 계산
# leaf_nodes = len(tree) - len(set(tree)) + 1
# # idx_list = list(filter(lambda x: tree[x] == remove_node, range(len(tree))))
# # print(idx_list)
# print(leaf_nodes)

# 양승열
# 입력부
n = int(input())
tree = list(map(int, input().split()))
remove_node = int(input())
leaf_nodes = 0
result_tree = []


def recursion(node):
    print(tree)
    idx_list = list(filter(lambda x: tree[x] == node, range(len(tree))))
    if not idx_list:
        return
    for idx in idx_list:
        tree[idx] = 10000
        recursion(idx)


if tree[remove_node] == -1:
    print(0)
    exit()
else:
    tree[remove_node] = 10000
    recursion(remove_node)
    result_tree = [i for i in tree if i != 10000]
    # leaf_node 계산
    leaf_nodes = len(result_tree) - len(set(result_tree)) + 1
    print(leaf_nodes)
