import math
N = (10**5) + 5  # Set N to a suitable value
sieve = [0] * (N + 1)
def preprocess():
    sieve[0] = sieve[1] = 1
    for i in range(2, int(math.sqrt(N)) + 1):
        if sieve[i]:
            for j in range(i * i, N + 1, i):
                sieve[j] = 1


def main():
    preprocess()
    # A = [
    #     [3,4,1,2],
    #     [3,4,5,1,2],
    #     [3,4,5,6,1,2],
    #     [3,4,5,6,7,1,2],
    # ]
    A = [ [3, 4, 1, 2], [3, 4, 5, 1, 2], [3, 4, 5, 6, 2, 1], [3, 4, 5, 6, 7, 1, 2] ]
    T = int(input())
    for _ in range(T):
        n = int(input())
        nn = n
        if(n<=3): print(-1)
        else:
            ans = []
            while n>3:
                p = len(ans)
                for x in A[n%4]:
                    ans.append(x+p)
                n -=len(A[n%4])
                
            for i in range(1,len(ans)+1): 
                assert(1<=ans[i-1]<=nn)
                assert(sieve[abs(i-ans[i-1])]==0)
            print(*ans)
            

if __name__ == "__main__":
    main()
