preorder = []
while True:
    try:
        preorder.append(int(input()))
    except:
        break

def postorder(left, right):
    if left > right:
        return
    else:
        root = preorder[left]   #
        div = right + 1
        for i in range(left + 1, right + 1):
            if root < preorder[i]:
                div = i
                break
        postorder(left + 1, div - 1)
        postorder(div, right)
        print(root)

postorder(0, len(preorder) - 1)