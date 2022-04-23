# 양승열 - dfs
ans_cnt = 0
# 입력부
magic_paper = list(input())
angel_bridge = list(input())
devil_bridge = list(input())


def cross_bridge(start, pos, flag):
    global magic_paper, ans_cnt

    if pos == len(magic_paper):
        ans_cnt += 1
        return

    if flag:
        for i in range(start, len(angel_bridge)):
            if angel_bridge[i] == magic_paper[pos]:
                cross_bridge(i + 1, pos + 1, not flag)
    else:
        for i in range(start, len(devil_bridge)):
            if devil_bridge[i] == magic_paper[pos]:
                cross_bridge(i + 1, pos + 1, not flag)


cross_bridge(0, 0, True)
cross_bridge(0, 0, False)
print(ans_cnt)
