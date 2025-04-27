import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

MOD = 10**9
dp = [[-1] * 10 for _ in range(1010)]

def solve(cur, num):
    if num < 0 or num > 9:
        return 0
    if dp[cur][num] != -1:
        return dp[cur][num]
    
    if cur == 1:
        return 1 if num != 0 else 0

    dp[cur][num] = solve(cur - 1, num - 1) + solve(cur - 1, num + 1)
    dp[cur][num] %= MOD

    return dp[cur][num]

n = int(input().rstrip())

result = 0
for i in range(10):
    result += solve(n, i)
    result %= MOD

print(result)