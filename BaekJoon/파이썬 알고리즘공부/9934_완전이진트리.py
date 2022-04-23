# 입력부
k = int(input())
treeInput = list(map(int, input().split()))

resultTree = [[] for _ in range(k)]


def inorder(tree, idx):
    root_idx = len(tree) // 2
    resultTree[idx].append(tree[root_idx])
    if len(tree) == 1:
        return
    inorder(tree[:root_idx], idx + 1)
    inorder(tree[root_idx + 1:], idx + 1)


inorder(treeInput, 0)

# 출력부
for i in resultTree:
    for j in i:
        print(j, end=' ')
    print()
