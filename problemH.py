import sys
import math

# input
t = 1
# solve here
sys.set_int_max_str_digits(5*(10**5) + 5)
def solve():
    s = input()
    t = int(s)
    def check(mid):
        if pow(6,mid)>t:
            return True
        return False
    lo = 0
    hi = 10**8
    ans = -1
    while lo<=hi:
        mid = (hi+lo)//2
        if not check(mid):
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    print(ans+1)
# input processing
for _ in range(t):
    solve()