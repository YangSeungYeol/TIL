# 양승열
from collections import defaultdict
import heapq

# 그래프 선언
graph = defaultdict(list)

# 입력부
n, e = map(int, input().split())

for i in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())


# dijkstra algorithm
def dijkstra(sp):
    # 최단 비용 리스트 선언(inf 초기화)
    route_length = [float('inf')] * (n + 1)

    # 자신 to 자신의 경로는 0으로 쳐야함 -> 이부분 반례 때문에 알게됨 ex) 시작 도착 == 경유1 경유2
    route_length[sp] = 0

    queue = []
    heapq.heappush(queue, (0, sp))

    while queue:
        # 최소 비용 노드에 대한 정보 꺼내기 -> 우선순위 큐 이므로!
        cost, now = heapq.heappop(queue)
        # 이미 처리된 적 있는 노드면 무시 -> 가장 저렴한 노드만 활용하면 되므로!
        if route_length[now] < cost:
            continue
        # node[0] : d / node[1] : price
        for node in graph[now]:
            cost_new = cost + node[1]
            # 현재 노드를 거치는게 더 저렴한 경우
            if route_length[node[0]] > cost_new:
                route_length[node[0]] = cost_new
                heapq.heappush(queue, (cost_new, node[0]))
    return route_length


start_1 = dijkstra(1)
start_v1 = dijkstra(v1)
start_v2 = dijkstra(v2)

shortest_path = min(start_1[v1] + start_v1[v2] + start_v2[n], start_1[v2] + start_v2[v1] + start_v1[n])

# 출력부
if shortest_path < float('inf'):
    print(shortest_path)
else:
    print(-1)
