import sys
import heapq
input = sys.stdin.readline

INF = 10**12

n = int(input().rstrip())
m = int(input().rstrip())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    s, e, c = map(int, input().split())
    adj[s].append((e, c))

s, e = map(int, input().split())

dist = [INF] * (n + 1)

pq = []
heapq.heappush(pq, (0, s))

while pq:
    cd, u = heapq.heappop(pq)
    if dist[u] <= cd:
        continue

    dist[u] = cd
    for v, w in adj[u]:
        nd = cd + w
        if dist[v] > nd:
            heapq.heappush(pq, (nd, v))

print(dist[e])

