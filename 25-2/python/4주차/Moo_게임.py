import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

MAX = 55
len = [0] * MAX
mx = 0

def dnc(cur, sz):
    if not sz:
        return 'm' if cur == 1 else 'o'
    
    if cur <= len[sz - 1]:
        return dnc(cur, sz - 1)
    elif cur > len[sz - 1] + sz + 3:
        return dnc(cur - len[sz - 1] - sz - 3, sz - 1)
    return 'm' if cur == len[sz - 1] + 1 else 'o'

n = int(input().strip())
len[0] = 3
for i in range(1, 55):
    len[i] = 2 * len[i - 1] + i + 3
    mx = i
    if len[i] > n:
        break

print(dnc(n, mx))

