from collections import Counter
def commonDigitLongestSubsequence(arr, n) :
    def solve(idx):
        if(idx==n): return Counter()
        cnt = solve(idx+1)
        mx = 0
        if(cnt):
            for x in str(arr[idx]):
                mx = max(mx,cnt[x])
        for x in str(arr[idx]):
            cnt[x] =mx+1
        return cnt
    return max(solve(0).values())

print(commonDigitLongestSubsequence([11,122,77,92,55,69,98],7))