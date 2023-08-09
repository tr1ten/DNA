from collections import defaultdict
# Function to count subarray having average
# exactly equal to K
def solve(A, k):
    A = [x-k for x in A]
    res = 0
    sm = 0
    pref = defaultdict(int)
    pref[0] = 1
    print(A)
    for x in A:
        sm += x
        res += pref[sm]
        pref[sm] +=1
    return res


print(solve([1, 4, 2, 6, 10], 4))
print(solve([12, 5, 3, 10, 4, 8, 10, 12, -6, -1], 6))
