def pp(N):
    for i in range(N):
        s = ['W','B']
        for j in range(N):
            print(s[j%2!=i%2],end="")
        print()


def solve(A):
    print(min(accumulate(A)))
    

def coloredZenga(A):
    K = 2;
    dp = [ [0]*K for _ in range(len(A))]
    dp[0][A[0]] = 1;
    for i in range(1,len(A)):
        if A[i]:
            dp[i][1] = min(max(1,dp[i-1][1]),dp[i-1][0] + 1)
            dp[i][0] = dp[i-1][0] + 1
        else:
            dp[i][0] = min(max(dp[i-1][0],1),dp[i-1][1] + 1)
            dp[i][1] = dp[i-1][1] + 1
    print(dp)
    return (min(dp[-1]))

print(coloredZenga(list(map(int,input().split()))))
# arr = list(map(int,input().split()))
# n = len(arr)
# a, b = 0, 0
# start = False
# for i in range(n):
#     if arr[i] == "white":
#         if not start:
#             start = True
#     else:
#         if start:
#             a += 1
#             start = False
# if start:
#     a += 1
# start = False
# for i in range(n):
#     if arr[i] == "red":
#         if not start:
#             start = True
#     else:
#         if start:
#             b += 1
#             start = False
#     if start:
#         b += 1


# print(min(a + 1, b + 1))