from collections import deque

node = int(input())
edge = int(input())

graph_list = {i+1: [] for i in range(node)}

for n in range(edge):
    node1, node2 = map(int, input().split())
    if node1 not in graph_list.keys():
        graph_list[node1] = [node2]
    else:
        graph_list[node1].append(node2)
    if node2 not in graph_list.keys():
        graph_list[node2] = [node1]
    else:
        graph_list[node2].append(node1)
array_list = [[0] for _ in range(n)]
for n in range(edge):
    map(int, graph_list)
print(graph_list)

def dfs(graph, root):
    visited = []
    stack = [1]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort(reverse=True)
                stack += temp
    return len(visited)-1\

def dfs_recursion(graph, root, visited=[]):
    visited.append(root)

    for node in graph[root]:
        if node not in visited:
            dfs_recursion(graph,node,visited)
    return len(visited)-1

def bfs(graph, root):
    visited = []
    queue = deque([1])

    while queue:
        n = queue.popleft()
        if n not in visited:
            visited.append(n)
            if n in graph:
                temp = list(set(graph[n]) - set(visited))
                temp.sort()
                queue += temp
    return len(visited)-1

print(dfs(graph_list, 1))
print(dfs_recursion(graph_list, 1))
print(bfs(graph_list, 1))


