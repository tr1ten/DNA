from typing import List, Tuple
from itertools import accumulate

def solve(pa: List[int], pb: List[int], pc: List[int], n: int, tar: int) -> List[int]:
    l = 2
    for r in range(1, n-1):
        while l <= r and pb[r+1] - pb[l] >= tar:
            l += 1
        l -= 1
        asum = pa[l]
        bsum = pb[r+1] - pb[l]
        csum = pc[n] - pc[r+1]
        if asum >= tar and bsum >= tar and csum >= tar:
            return [1, l, l+1, r+1, r+2, n]
    return [-1, -1, -1, -1, -1, -1]

def testcase():
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    c = list(map(int, input().strip().split()))
    
    pa = [0] + list(accumulate(a))
    pb = [0] + list(accumulate(b))
    pc = [0] + list(accumulate(c))
    
    total = pa[-1]  # total sum of a, which should be equal to total sum of b and c
    assert total == pb[-1] and total == pc[-1]
    
    tar = (total + 2) // 3
    res = solve(pa, pb, pc, n, tar)
    
    if res[0] == -1:
        res = solve(pc, pb, pa, n, tar)
        res[0], res[5] = res[5], res[0]
        res[1], res[4] = res[4], res[1]
    
    if res[0] == -1:
        res = solve(pb, pa, pc, n, tar)
        res[0], res[2] = res[2], res[0]
        res[1], res[3] = res[3], res[1]
    
    if res[0] == -1:
        res = solve(pc, pa, pb, n, tar)
        res[0], res[2] = res[2], res[0]
        res[1], res[3] = res[3], res[1]
        res[2], res[4] = res[4], res[2]
        res[3], res[5] = res[5], res[3]
    
    if res[0] == -1:
        res = solve(pa, pc, pb, n, tar)
        res[2], res[4] = res[4], res[2]
        res[3], res[5] = res[5], res[3]
    
    if res[0] == -1:
        res = solve(pb, pc, pa, n, tar)
        res[0], res[2] = res[2], res[0]
        res[1], res[3] = res[3], res[1]
        res[0], res[4] = res[4], res[0]
        res[1], res[5] = res[5], res[1]
    
    assert len(res) == 6
    if res[0] == -1:
        res = [-1]
    
    print(" ".join(map(str, res)))

def main():
    T = int(input().strip())
    for _ in range(T):
        testcase()

if __name__ == "__main__":
    main()
