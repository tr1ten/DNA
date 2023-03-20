def main():
    N, T = map(int, input().split())
    A = list(map(int, input().split()))
    def ok(mid):
        return sum(mid//a for a in A) >= T
    lo, hi = 0, 10**18
    while lo<hi:
        mid = (lo+hi)//2
        if(ok(mid)):
            hi = mid
        else: lo = mid+1
    print(lo)
if __name__ == "__main__":
    main()
