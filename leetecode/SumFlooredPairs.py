class Solution:
    def sumOfFlooredPairs(self, A: List[int]) -> int:
        incs,cnt = [0]*(max(A) + 1),Counter(A)
        for x in cnt:
            for dev in range(x,len(incs),x):
                incs[dev]+= cnt[x]
        acc = list(accumulate(incs))
        return sum([acc[q] for q in A])%(10**9 + 7)