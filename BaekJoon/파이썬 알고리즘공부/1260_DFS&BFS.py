from collections import deque

graph_list = { }
node, edge, root = input().split()
node, edge, root = int(node), int(edge), int(root)

for n in range(edge):
    node1, node2 = input().split()
    node1, node2 = int(node1), int(node2)
    if node1 not in graph_list.keys():
        graph_list[node1] = [node2]
    else:
        graph_list[node1].append(node2)
    if node2 not in graph_list.keys():
        graph_list[node2] = [node1]
    else:
        graph_list[node2].append(node1)

print(graph_list)

def DFS_with_adj_list(graph, root):
    visited = []
    stack = [root]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack += temp
    return " ".join(str(i) for i in visited)

def BFS_with_adj_list(graph, root):
    visited = []
    queue = deque([root])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue += temp
    return " ".join(str(i) for i in visited)

print(DFS_with_adj_list(graph_list, root))
print(BFS_with_adj_list(graph_list, root))


