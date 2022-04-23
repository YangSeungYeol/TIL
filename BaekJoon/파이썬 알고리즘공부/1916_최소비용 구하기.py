# 양승열
from collections import defaultdict
import heapq
# 입력부
n = int(input())
m = int(input())

# 그래프 선언 / 최단 비용 리스트 선언(inf로 초기화)
graph = defaultdict(list)
total_cost = [float('inf')] * (n + 1)

# 그래프 입력
for _ in range(m):
    s, d, price = map(int, input().split())
    graph[s].append((d, price))

start, end = map(int, input().split())


# dijkstra algorithm
def dijkstra(sp):
    queue = []
    heapq.heappush(queue, (0, sp))

    while queue:
        # 최소 비용 노드에 대한 정보 꺼내기 -> 우선순위 큐 이므로!
        cost, now = heapq.heappop(queue)
        # 이미 처리된 적 있는 노드면 무시 -> 가장 저렴한 노드만 활용하면 되므로!
        if total_cost[now] < cost:
            continue
        # node[0] : d / node[1] : price
        for node in graph[now]:
            cost_new = cost + node[1]
            # 현재 노드를 거치는게 더 저렴한 경우
            if total_cost[node[0]] > cost_new:
                total_cost[node[0]] = cost_new
                heapq.heappush(queue, (cost_new, node[0]))


dijkstra(start)

# 출력부
print(total_cost[end])
