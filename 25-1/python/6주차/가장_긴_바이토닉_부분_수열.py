import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
a = [0] + A

dp = [[-1] * 2 for _ in range(n + 1)]

def solve(cur, cnt):
    if dp[cur][cnt] != -1:
        return dp[cur][cnt]
    
    ret = 1
    if cnt == 1:
        for i in range(1, cur):
            if a[i] <= a[cur]:
                continue
            ret = max(ret, solve(i, 0) + 1, solve(i, 1) + 1)
    else:
        for i in range(1, cur):
            if a[i] >= a[cur]:
                continue
            ret = max(ret, solve(i, 0) + 1)

    dp[cur][cnt] = ret
    return ret

ans = 0
for i in range(1, n + 1):
    ans = max(ans, solve(i, 0), solve(i, 1))

print(ans)

