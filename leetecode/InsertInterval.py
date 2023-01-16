class Solution:
    def insert(self, ivals: List[List[int]], ni: List[int]) -> List[List[int]]:
        res = []
        j = 0
        ts,te = ni
        while(j<len(ivals)):
            s,e = ivals[j]
            if(e<ts):
                res.append(ivals[j])
                j+=1
            else:
                end = max(te,e)
                while(j<len(ivals) and ivals[j][0]<=te):
                    end = max(ivals[j][1],end)
                    j+=1
                res.append([min(ts,s),end])
        return res