def maximazation():
    # 정답의 범위는 1 ~ 2^31 - 1
    lo = 1
    hi = 2 ** 31 - 1
    while lo < hi:
        mid = (lo + hi + 1) // 2 # 중간값
        # 결정 문제의 답이 1 이면
        # 정답은 [mid, hi]에 존재
        if(decision(mid)):
            lo = mid

        # 결정 문제의 답이 0 이면
        # 정답은 [lo, mid - 1]에 존재
        else:
            hi = mid - 1
    return lo

def minimazation():
    # 정답의 범위는 1 ~ l
    lo = 1
    hi = l
    while(lo < hi):
        mid = (lo + hi) // 2 # 중간값
        # 결정 문제의 답이 1 이면
        # 정답은 [lo, mid]에 존재
        if(decision(mid)):
            hi = mid
        
        # 결정 문제의 답이 0 이면
        # 정답은 [mid + 1, hi]에 존재
        else:
            lo = mid + 1
    return lo
