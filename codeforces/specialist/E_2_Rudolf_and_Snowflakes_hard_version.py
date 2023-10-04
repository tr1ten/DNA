def fast_pow(base, exp):
    result = 1
    while exp > 0:
        if exp % 2 == 1:
            result = result * base
        base = base * base
        exp = exp // 2
    return result

def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        MX = 62
        f = 0
        for c in range(3, MX + 1):
            lo = 2
            hi = int(pow(n,1/(c-1)))+1;
            ans = 0
            while lo <= hi:
                mid = (lo + hi) // 2
                from_pow = fast_pow(mid, c)
                to = (n * (mid - 1)) + 1
                if from_pow >= to:
                    hi = mid - 1
                    ans = mid
                else:
                    lo = mid + 1
            if ans and ans**c == (n * (ans - 1) + 1):
                f = 1
                # print(ans,c,((10**18 // n) + 2, int(10**((18 * 1.0) / c)) + 1));
                break
        if f:
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    main()
