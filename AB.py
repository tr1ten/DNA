def printMaxOfMin(arr, n):
    s = []
    left = [-1] * (n + 1)
    right = [n] * (n + 1)

    for i in range(n):
        while (len(s) != 0 and
            arr[s[-1]] <= arr[i]):
            s.pop()

        if (len(s) != 0):
            left[i] = s[-1]

        s.append(i)
    while (len(s) != 0):
        s.pop()
    for i in range(n - 1, -1, -1):
        while (len(s) != 0 and arr[s[-1]] <= arr[i]):
            s.pop()

        if(len(s) != 0):
            right[i] = s[-1]

        s.append(i)
    ans = [float('inf')] * (n + 1)
    for i in range(n):
        Len = right[i] - left[i] - 1

        ans[Len] = min(ans[Len], arr[i])
    for i in range(n - 1, 0, -1):
        ans[i] = min(ans[i], ans[i + 1])

    return ans

if __name__ == '__main__':
    n,q = map(int,input().split())
    arr = list(map(int,input().split()))
    ans = printMaxOfMin(arr, n)
    for x in range(q):
        i = int(input())
        print(ans[i])

