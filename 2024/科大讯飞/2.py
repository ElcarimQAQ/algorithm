import heapq


def dijkstra(graph, start, end):
    nodes = [(0, start)] # queue
    costs = {node: float('inf') for node in nodes}
    costs[start] = 0
    visited = set()

    while nodes:
        dist, node = heapq.heappop(nodes)
        if dist > costs[node]:
            continue
        visited.add(node)
        
        for neighbor, weight in graph[node].items():
            new_cost = dist + weight
            if new_cost < costs.get(neighbor, float('inf')):
                costs[neighbor] = new_cost
                heapq.heappush(nodes, (new_cost, neighbor))

    return costs[end]

n, m, s, t = map(int, input().split())
graph = {i: {} for i in range(1, n+1)}

for i in range(m):
    u, v = map(int, input().split())
    graph[u][v] = 1
    graph[v][u] = 1

edge = list(map(int, input().split()))
edge_nums = dijkstra(graph, s, t)
sorted_edge = sorted(edge)
dist = 0
for i in range(edge_nums):
    dist += sorted_edge[i]
print(dist)