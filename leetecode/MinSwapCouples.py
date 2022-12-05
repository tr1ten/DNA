class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        res = 0
        d = dict()
        def swap(i,j):
            row[i],row[j] = row[j],row[i]
            d[row[j]] = j
            d[row[i]] = i
        for i in range(len(row)):
            d[row[i]] = i
        for i in range(0,len(row),2):
            if(row[i+1]!=row[i]^1):
                res +=1
                swap(i+1,d[row[i]^1])
        return res