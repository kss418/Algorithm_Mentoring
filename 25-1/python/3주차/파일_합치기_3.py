import sys
import heapq
input = sys.stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    a = list(map(int, input().rstrip().split()))
    result = 0

    pq = []
    for i in a:
        heapq.heappush(pq, i)
        
    while len(pq) > 1:
        fi = heapq.heappop(pq)
        se = heapq.heappop(pq)

        heapq.heappush(pq, fi + se)
        result += fi + se

    print(result)